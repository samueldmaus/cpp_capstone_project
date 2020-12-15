#include <iostream>
#include <sstream>
#include <ctime>
#include "app_gui.h"

bool MyApp::OnInit() {
    // create window with name and shows it
    AppFrame *my_app = new AppFrame(wxT("My App"));
    my_app->Show(true);
    SetTopWindow(my_app);
    return true;
}

// create wxWidgets frame
AppFrame::AppFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 400))
{
  Connect(wxEVT_PAINT, wxPaintEventHandler(AppFrame::OnPaint));
  Centre();
}

// draw the month, day, year, time (DrawText has to use stringstream)
void AppFrame::OnPaint(wxPaintEvent& event) {
  wxPaintDC dc(this);
  while(true) {
    auto dt = AppFrame::GetTime();
    std::stringstream str;
    str << dt;
    dc.DrawText(str.str().c_str(), 20, 20);
  }
}

char* AppFrame::GetTime() {
  std::time_t now = time(0);
  char* dt = ctime(&now);
  return dt;
}

// implement wxWidgets application
IMPLEMENT_APP(MyApp)
