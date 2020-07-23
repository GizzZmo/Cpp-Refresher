#include<iostream>
#include<stack>
#include<string>
#include<regex>
using namespace std;

bool isOpenParenthesis(char);
bool isClosingParenthesis(char);
bool highPrecedence(char, char);

int main(int argc, char const *argv[])
{
    string result;
    stack<char> charStack;
    string infExp = "((A+B)*C-D)*E";
    regex isOperator("[-+*/]");
    for(int i=0;i<infExp.length();i++) {
        if(isOpenParenthesis(infExp[i])){
            charStack.push(infExp[i]);
        }
        else if(infExp[i]>='A' && infExp[i] <= 'Z') {
            result += infExp[i];
        }
        else if(regex_match(string(1,infExp[i]), isOperator)){
            while(!charStack.empty() && charStack.top()!='(' && highPrecedence(charStack.top(), infExp[i])) {
                result += charStack.top();
                charStack.pop();
            }
            charStack.push(infExp[i]);
        }
        else if(isClosingParenthesis(infExp[i])) {
            while(!charStack.empty() && charStack.top()!='(') {
                result += charStack.top();
                charStack.pop();
            }
            charStack.pop();
        }
    }
    while(!charStack.empty()){
        result+=charStack.top();
        charStack.pop();
    }
    cout << "Postfix exp : "<< result;
    return 0;
}

bool isOpenParenthesis(char ch){
    return (ch=='(');
}

bool isClosingParenthesis(char ch){
    return (ch==')');
}

int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
        break;
	case '*':
	case '/':
		weight = 2;
        break;
	}
	return weight;
}

bool highPrecedence(char op1, char op2) {
    int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

    return op1Weight>=op2Weight;
}