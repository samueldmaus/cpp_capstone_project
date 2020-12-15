#ifndef APP_GUI_H
#define APP_GUI_H

#include <wx/wx.h>


class AppFrame : public wxFrame
{
public:
    AppFrame(const wxString& title);

};

class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};

#endif
