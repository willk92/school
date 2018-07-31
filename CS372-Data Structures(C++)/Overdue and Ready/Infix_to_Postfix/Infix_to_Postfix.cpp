/*
William Kelley
CS372 - ASU
St ID: 70391
--------------------
Infix_to_Postfix.cpp
*Translating infix expression to postfix expression*

*/

#include "general_list.h"
#include "stacky_template.cpp"

#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

//NOTE THERE IS NO STACK LIBRARY INCLUDED
//I noticed I named my class the same as the library <stack> does.

using namespace std;

template <class ElementType>

int main()
{
}

bool is_operand(ElementType a) {
    if ((a >= '0' && a <= '9') || (a >= 0 && a <= 9) 
     || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}

bool is_operator(ElementType a) {
    if((a == '+') || (a == '-') || (a == '*') || (a == '/')) {
        return true;
    }
    else {
        return false;
    }
}

bool is_right_assoc(ElementType a) {
    return false;
}

int operator_weight(ElementType a) {
    int weight = 0;
    switch(a) {
        case '+':
        case '-':
        weight = 1;
        break;
        case '*':
        case '/':
        weight = 2;
        break;
        case '^':
        weight = 3;
        break;
    }
    return weight;
}

string inf_to_post(ElementType a) {
    stack exp;
    string postfix = NULL;

    for (int i = 0; i < exp.size(); i++) {
        if(exp.get_element(i) == ' ') {
            continue;
        }
        else if (is_operator(exp.get_element(i))) {
            while(!exp.empty()) {
                postfix = postfix += exp.top();
                exp.pop();
            }
            exp.push(i);
        }
        else if (is_operand(exp.get_element(i))) {
            postfix += exp.get_element();
        }
    }
    while (!exp.empty()) {
        postfix = postfix + exp.top();
        exp.pop();
    }
    return postfix;
}