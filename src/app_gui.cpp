#include <iostream>
#include <sstream>
#include <string>
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
    my_app_dialog.button = new wxButton(this, 1, row);
    my_app_dialog.button->Bind(wxEVT_BUTTON, &AppFrame::OnButtonClick, this);
    grd_sizer->Add(my_app_dialog.button, 0, wxEXPAND);
  }

  sizer->Add(grd_sizer, 1, wxEXPAND);
  SetSizer(sizer);
  Centre();
}

// function to display button val to wxTextCtrl (have to dynamically cast wxObject into a wxButton in order for GetLabel method to work)
void AppFrame::OnButtonClick(wxCommandEvent& event) {
    auto cur_val = my_app_dialog.eq_display->GetValue();
    my_app_dialog.clicked_button = dynamic_cast<wxButton*>(event.GetEventObject());
    my_app_dialog.eq_display->SetValue(cur_val + my_app_dialog.clicked_button->GetLabel());
}

// function to clear the input of the wxTextCtrl
void AppFrame::ClearTextCtrl(wxCommandEvent& event) {
   my_app_dialog.eq_display->SetValue("");
}

void AppFrame::DelLastInput(wxCommandEvent& event) {
  auto length = my_app_dialog.eq_display->GetLastPosition();
  auto edit_val = my_app_dialog.eq_display->GetRange(0, (length - 1));
  my_app_dialog.eq_display->SetValue(edit_val);
}

// implement wxWidgets application
IMPLEMENT_APP(MyApp)
