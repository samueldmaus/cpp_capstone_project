#ifndef APP_GUI_H
#define APP_GUI_H

#include <iostream>
#include <sstream>
#include <string>
#include <future>
#include <thread>
#include <memory>
#include <functional>
#include <deque>
#include <math.h>
#include <wx/wx.h>
#include <wx/string.h>
#include <wx/time.h>
#include <wx/event.h>

// wxWidgets Frame that controls all elements
class AppFrame : public wxFrame
{
public:
    AppFrame(const wxString& title);
    void OnButtonClick(wxCommandEvent& event); // put value of button into text field
    void ClearTextCtrl(wxCommandEvent& event); // clear the text field
    void DelLastInput(wxCommandEvent& event); // delete the last entered value from the text field
    void GetEquation(wxCommandEvent& event); // start solving equation in either standard or scientific mode
    void SolveEquation(std::promise<wxString> &&prms, wxString &equation); // standard mode solving
    std::string DoMath(wxString &equation); // standard mode solving
    void GetOperatorIndex(wxString &equation); // get index of operators, help with solving in standard mode
    void OnQuit(wxCommandEvent& event); // close app
    void SwitchCalcTypes(wxCommandEvent& event); // checking to see which mode the calc is
    wxBoxSizer *sizer;
    wxGridSizer *grd_sizer;
    std::deque<int> operator_index;
    wxMenuBar *menubar;
    wxMenu *file;
    wxMenu *type;
    wxMenuItem *standard;
    wxMenuItem *scientific;
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
