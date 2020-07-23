#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool CheckBalancedParenthesis(string);
char findCompatibleParenthesis(char);

int main(int argc, char const *argv[])
{
    string expression="{[(A+b)+(c-d)]*e}";
    cout << CheckBalancedParenthesis(expression);
    return 0;
}

bool CheckBalancedParenthesis(string expression) {
    stack<char> parenthesisstack;
    for(auto ch: expression) {
        if(ch=='(' || ch=='[' || ch=='{') {
            parenthesisstack.push(ch);
        }
        else if(ch==')' || ch==']' || ch=='}') {
            if(!parenthesisstack.size())
                return false;
            else {
                char stackOpenChar = parenthesisstack.top();
                if(stackOpenChar != findCompatibleParenthesis(ch)) {
                    return false;
                }
                else {
                    parenthesisstack.pop();
                }
            }
        }
        else {
            continue;
        }
    }
    if(parenthesisstack.size()!=0)
        return false;
    else
        return true;
}

char findCompatibleParenthesis(char closingParenthesis) {
    char ch;
    switch(closingParenthesis) {
        case ')': ch = '(';
                  break;
        case ']': ch = '[';
                  break;
        case '}': ch = '{'; 
                  break;
    }
    return ch;
}
