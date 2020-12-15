#include "app_gui.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    AppFrame *simple = new AppFrame(wxT("Simple"));
    simple->Show(true);

    return true;
}

AppFrame::AppFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150))
{
  Centre();
}
