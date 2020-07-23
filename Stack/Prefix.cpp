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
    string prefixExpression = "- + * 2 3 * 5 4 9";
    reverse(prefixExpression.begin(), prefixExpression.end());
    istringstream ss(prefixExpression);
    while(ss) {
        string token;
        ss >> token;
        regex isDigit("\\d+");
        regex isOperator("[-+/*]");
        if(regex_match(token, isDigit)){
            postFixStack.push(stoi(token));
        } 
        else if(regex_match(token, isOperator)){
            int op1 = postFixStack.top();
            postFixStack.pop();
            int op2 = postFixStack.top();
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
