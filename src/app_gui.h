#ifndef APP_GUI_H
#define APP_GUI_H

#include <wx/wx.h>
#include <wx/event.h>
#include <ctime>
#include <mutex>
#include <deque>
#include <vector>

// wxWidgets Frame that controls all elements
class AppFrame : public wxFrame
{
public:
    AppFrame(const wxString& title);
    void OnButtonClick(wxCommandEvent& event);
    void ClearTextCtrl(wxCommandEvent& event);
    void DelLastInput(wxCommandEvent& event);
    void GetEquation(wxCommandEvent& event);
    void SolveEquation(std::promise<wxString> &&prms, wxString &equation);
    std::string DoMath(wxString &equation);
    void GetOperatorIndex(wxString &equation);
    void OnQuit(wxCommandEvent& event);
    wxBoxSizer *sizer;
    wxGridSizer *grd_sizer;
    std::deque<int> operator_index;
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
