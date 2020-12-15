#include <iostream>
#include <sstream>
#include <string>
#include <wx/time.h>

#include "app_gui.h"
#include "dialog.cpp"

BEGIN_EVENT_TABLE(AppFrame, wxFrame)
  EVT_BUTTON()
END_EVENT_TABLE()

// array for button labels
wxString rows[] = {wxString(wxT("7")), wxString(wxT("8")), wxString(wxT("9")), wxString(wxT("/")), wxString(wxT("4")), wxString(wxT("5")), wxString(wxT("6")),
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

  grd_sizer->Add(new wxButton(this, -1, wxT("Cls")), 0, wxEXPAND);
  grd_sizer->Add(new wxButton(this, -1, wxT("Bck")), 0, wxEXPAND);
  grd_sizer->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
  grd_sizer->Add(new wxButton(this, -1, wxT("Close")), 0, wxEXPAND);

  // everything for the buttons
  for (wxString &row : rows) {
    button = new wxButton(this, -1, row);
    grd_sizer->Add(button, 0, wxEXPAND);
  }

  sizer->Add(grd_sizer, 1, wxEXPAND);
  SetSizer(sizer);
  Centre();
}

// implement wxWidgets application
IMPLEMENT_APP(MyApp)
