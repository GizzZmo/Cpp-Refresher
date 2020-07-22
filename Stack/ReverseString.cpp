#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    string input="c++ IS FUN", output;
    stack<char> S;
    for(char ch: input) {
        S.push(ch);
    }
    for(int i=0; i<input.length(); i++) {
        auto topStackChar = S.top();
        output+=topStackChar;
        S.pop();
    }
    cout<< "Reversed string : " << output;
    return 0;
}
