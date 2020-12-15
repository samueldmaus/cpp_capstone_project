#ifndef DIALOG_H
#define DIALOG_H

#include <wx/wx.h>

class MyDialog : public wxDialog
{
public:
    void WxButtonClick(wxCommandEvent& WXUNUSED(event));
    wxTextCtrl *eq_display;
    wxButton *button;
    wxStaticText eq_text;
private:

};

#endif