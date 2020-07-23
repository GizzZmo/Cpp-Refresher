#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<regex>
using namespace std;

int compute(int, int, string);

int main(int argc, char const *argv[])
{
    stack<int> postFixStack;
    string postfixExpression = "2 3 * 6 4 * + 9 -";
    istringstream ss(postfixExpression);
    while(ss) {
        string token;
        ss >> token;
        regex isDigit("\\d+");
        regex isOperator("[-+/*]");
        if(regex_match(token, isDigit)){
            postFixStack.push(stoi(token));
        } 
        else if(regex_match(token, isOperator)){
            int op2 = postFixStack.top();
            postFixStack.pop();
            int op1 = postFixStack.top();
            postFixStack.pop();
            int temp = compute(op1, op2, token);
            postFixStack.push(temp);
        }
    }
    cout << "Result : " << postFixStack.top();
    return 0;
}

int compute(int op1, int op2, string op) {
    int result;
    switch(op[0]) {
        case '+': result = op1+op2;
                  break;
        case '-': result = op1-op2;
                  break;
        case '*': result = op1 * op2;
                  break;
        case '/': result = op1 / op2;
                  break;
        default : result = 0;
                  break;
    }
    return result;
}
