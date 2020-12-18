#include <iostream>
#include <sstream>
#include <string>
#include <future>
#include <thread>
#include <memory>
#include <functional>
#include <vector>
#include <wx/string.h>
#include <wx/time.h>

#include "app_gui.h"
#include "dialog.cpp"

// event table handler

// array for button labels
wxString rows[] = {_("7"), _("8"), wxString(wxT("9")), wxString(wxT("/")), wxString(wxT("4")), wxString(wxT("5")), wxString(wxT("6")),
  wxString(wxT("x")), wxString(wxT("1")), wxString(wxT("2")), wxString(wxT("3")), wxString(wxT("-")), wxString(wxT("0")), wxString(wxT(".")),
  wxString(wxT("=")), wxString(wxT("+"))};

bool MyApp::OnInit() {
    // create window with name and shows it
    AppFrame *my_app = new AppFrame(wxT("Sam's Calculator"));
    my_app->Show(true);
    SetTopWindow(my_app);
    return true;
}

// create wxWidgets frame
AppFrame::AppFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxPoint(-1, -1), wxSize(400, 400))
{
  // create text ctrl for displaying the numbers
  sizer = new wxBoxSizer(wxVERTICAL);
  my_app_dialog.eq_display = new wxTextCtrl(this, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_READONLY | wxTE_RIGHT);
  sizer->Add(my_app_dialog.eq_display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);

  grd_sizer = new wxGridSizer(5, 4, 2, 2);

  // top row of buttons
  wxButton* BUTTON_CLEAR = new wxButton(this, -1, _("CLEAR"));
  grd_sizer->Add(BUTTON_CLEAR, 0, wxEXPAND);
  BUTTON_CLEAR->Bind(wxEVT_BUTTON, &AppFrame::ClearTextCtrl, this);

  wxButton* BUTTON_DEL = new wxButton(this, -1, _("DEL"));
  BUTTON_DEL->Bind(wxEVT_BUTTON, &AppFrame::DelLastInput, this);
  grd_sizer->Add(BUTTON_DEL, 0, wxEXPAND);

  grd_sizer->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
  grd_sizer->Add(new wxButton(this, -1, wxT("QUIT")), 0, wxEXPAND);

  // everything for the buttons
  for (wxString &row : rows) {
    if(row == "=") {
      my_app_dialog.button = new wxButton(this, 1, row);
      my_app_dialog.button->Bind(wxEVT_BUTTON, &AppFrame::GetEquation, this);
      grd_sizer->Add(my_app_dialog.button, 0, wxEXPAND);
    } else {
      my_app_dialog.button = new wxButton(this, 1, row);
      my_app_dialog.button->Bind(wxEVT_BUTTON, &AppFrame::OnButtonClick, this);
      grd_sizer->Add(my_app_dialog.button, 0, wxEXPAND);
    }
  }

  sizer->Add(grd_sizer, 1, wxEXPAND);
  SetSizer(sizer);
  Centre();
}

// function to display button val to wxTextCtrl (have to dynamically cast wxObject into a wxButton in order for GetLabel method to work)
void AppFrame::OnButtonClick(wxCommandEvent& event) {
  std::lock_guard<std::mutex> lck(mtx_);
  auto cur_val = my_app_dialog.eq_display->GetValue();
  my_app_dialog.clicked_button = dynamic_cast<wxButton*>(event.GetEventObject()); //event.GetEventObject is the object that had the event performed on it(button) - have to cast it to wxButton as it starts as a wxObject
  my_app_dialog.eq_display->SetValue(cur_val + my_app_dialog.clicked_button->GetLabel());
}

// function to clear the input of the wxTextCtrl
void AppFrame::ClearTextCtrl(wxCommandEvent& event) {
  my_app_dialog.eq_display->SetValue("");
}

// function to delete the last input of the wxTextCtrl
void AppFrame::DelLastInput(wxCommandEvent& event) {
  auto length = my_app_dialog.eq_display->GetLastPosition();
  auto edit_val = my_app_dialog.eq_display->GetRange(0, (length - 1));
  my_app_dialog.eq_display->SetValue(edit_val);
}

// function to get started solve equation
void AppFrame::GetEquation(wxCommandEvent& event) {
  auto cur_equation = my_app_dialog.eq_display->GetValue();
  std::promise<wxString> prms;
  std::future<wxString> ftr = prms.get_future();
  std::thread t_1(&AppFrame::SolveEquation, this, std::move(prms), std::ref(cur_equation));
  try {
    auto solved_equation = ftr.get();
    my_app_dialog.eq_display->SetValue(solved_equation);
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }
  t_1.join();
}

void AppFrame::SolveEquation(std::promise<wxString> &&prms, wxString &equation) {
  // 10 is just a place holder for right now, trying to see if I can just get a string passed back
  AppFrame::GetOperatorIndex(equation);
  std::string final_answer = AppFrame::DoMath(equation);
  prms.set_value(final_answer);
}

std::string AppFrame::DoMath(wxString &equation) {
  std::string result = "";
  equation.ToStdString();
  while(!AppFrame::operator_index.empty()) {
    if(AppFrame::operator_index.size() != 1) {
      return result;
    } else {
      auto num_1 = wxAtoi(equation.substr(0, AppFrame::operator_index[0]));
      auto num_2 = wxAtoi(equation.substr(AppFrame::operator_index[0] + 1));
      if(equation[AppFrame::operator_index[0]] == '+') {
        std::cout << "num 1 is " << num_1 << std::endl;
        std::cout << "num 2 is " << num_2 << std::endl;
        auto num_result = num_1 + num_2;
        result = std::to_string(num_result);
        AppFrame::operator_index.erase(AppFrame::operator_index.begin());
      } else if (equation[AppFrame::operator_index[0]] == '-') {
        auto num_result = num_1 - num_2;
        result = std::to_string(num_result);
        AppFrame::operator_index.erase(AppFrame::operator_index.begin());
      } else if (equation[AppFrame::operator_index[0]] == 'x') {
        auto num_result = num_1 * num_2;
        result = std::to_string(num_result);
        AppFrame::operator_index.erase(AppFrame::operator_index.begin());
      } else if (equation[AppFrame::operator_index[0]] == '/') {
        auto num_result = num_1 / num_2;
        result = std::to_string(num_result);
        AppFrame::operator_index.erase(AppFrame::operator_index.begin());
      }
    }

  }
  return result;
}

void AppFrame::GetOperatorIndex(wxString equation) {
  equation.ToStdString();
  for (int i = 0; i < equation.length(); i++) {
    if (equation[i] == '+' || equation[i] == '-' || equation[i] == 'x' || equation[i] == '/') {
      AppFrame::operator_index.push_back(i);
    }
  }
  /* just prints indexes of the operators
  for(int num : AppFrame::operator_index) {
    std::cout << num << std::endl;
  }
  */
}

// implement wxWidgets application
IMPLEMENT_APP(MyApp)
