#include "stack.h"

wxString Stack::ScientificEquation(wxString &equation) {
    wxString solved_equation;
    std::promise<wxString> prms;
    std::future<wxString> ftr = prms.get_future();
    std::thread t_1(&Stack::SolveEquationScientific, this, std::move(prms), std::ref(equation));
    try {
        solved_equation = ftr.get();
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }
    t_1.join(); // join the thread
    return solved_equation;
}

bool Stack::isOperator(char c) {
    if(c == '+' || c == '-' || c== '/' || c == 'x' || c == '^') {
        return true;
    } else {
        return false;
    }
}

int Stack::Precedence(char c) {
    if(c == '^') {
        return 3;
    } else if(c == 'x' || c == '/') {
        return 2;
    } else if(c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

void Stack::SolveEquationScientific(std::promise<wxString> &&prms, wxString &equation) {
    std::string infix = Stack::infixToPostfix(equation, infix_stack);
    int value = Stack::evaluatePostfix(infix, postfix_stack);
    wxString final_answer = wxString::Format(wxT("%i"), value);
    prms.set_value(final_answer);
}

std::string Stack::infixToPostfix(wxString &infix, std::stack<char> &s) {
    std::string postfix;
    for (int i = 0; i < infix.length(); i++) {
        if(isdigit(infix[i])) {
            postfix += infix[i];
        } else if(infix[i] == '(') {
            s.push(infix[i]);
        } else if(infix[i] == ')') {
            while(s.top() != '(' && !s.empty()) {
                char temp = s.top();
                postfix += temp;
                s.pop();
            }
            if(s.top() == '(') {
                s.pop();
            }
        } else if(isOperator(infix[i])) {
            if(s.empty()) {
                s.push(infix[i]);
            } else {
                if(Precedence(infix[i]) > Precedence(s.top())) {
                    s.push(infix[i]);
                } else if (Precedence(infix[i]) == Precedence(s.top()) && infix[i] == '^') {
                    s.push(infix[i]);
                } else {
                    while(!s.empty() && Precedence(infix[i]) <= Precedence(s.top())) {
                        char temp = s.top();
                        postfix += temp;
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.empty()) {
        char temp = s.top();
        postfix += temp;
        s.pop();
    }
    return postfix;
}

int Stack::evaluatePostfix(std::string &postfix, std::stack<int> &a) {
    int val;
    for (int i = 0; i < postfix.length(); i++) {
        if(isdigit(postfix[i])) {
            a.push(postfix[i] - 48);
        } else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == 'x' || postfix[i] == '/' || postfix[i] == '^') {
            int num_1 = a.top();
            a.pop();
            int num_2 = a.top();
            a.pop();
            switch(postfix[i])
            {
                case '+':
                    val = num_2 + num_1;
                    a.push(val);
                    break;
                case '-':
                    val = num_2 - num_1;
                    a.push(val);
                    break;
                case 'x':
                    val = num_2 * num_1;
                    a.push(val);
                    break;
                case '/':
                    val = num_2 / num_1;
                    a.push(val);
                    break;
                case '^':
                    val = pow(num_2, num_1);
                    a.push(val);
                    break;
            }
        }
    }
    return a.top();
}

