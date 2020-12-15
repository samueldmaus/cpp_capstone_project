#ifndef APP_GUI_H
#define APP_GUI_H

#include <wx/wx.h>
#include <ctime>
#include <mutex>

// wxWidgets Frame that controls all elements
class AppFrame : public wxFrame
{
public:
    AppFrame(const wxString& title);
    wxBoxSizer *sizer;
    wxGridSizer *grd_sizer;
    wxTextCtrl *eq_display;
private:
    std::mutex mtx_;
};

// wxWidgets app that hides main()
class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};


#endif
