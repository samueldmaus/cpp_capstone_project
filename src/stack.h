#ifndef STACK_H
#define STACK_H

#include <stack>
#include <math.h>
#include <string>
#include <wx/wx.h>

class Stack {
public:
    std::stack<char> infix_stack;
    std::stack<int> postfix_stack;
    bool isOperator(char c);
    int Precedence(char c);
    void ScientificEquation(wxString &equation);
    void SolveEquationScientific(std::promise<wxString> &&prms, wxString &equation);
    std::string infixToPostfix(wxString &infix, std::stack<char> &s);
    int evaluatePostfix(std::string &postfix, std::stack<int> &a);
};

#endif  