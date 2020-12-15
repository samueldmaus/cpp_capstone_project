#ifndef APP_GUI_H
#define APP_GUI_H

#include <wx/wx.h>
#include <ctime>

// wxWidgets Frame that controls all elements
class AppFrame : public wxFrame
{
public:
    AppFrame(const wxString& title);
    void OnPaint(wxPaintEvent& event);
    char* GetTime();
};

// wxWidgets app that hides main()
class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};


#endif
