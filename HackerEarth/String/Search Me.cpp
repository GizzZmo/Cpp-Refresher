#include<bits/stdc++.h>
using namespace std;

string text;
int LT, LP;
string pattern = "to the";

bool match(int start, int end) {
    for(int i=start,j=0;i<=end;i++,j++) {
        if(pattern[j]!=text[i])
            return false;
    }
    if(start) {
        if(text[start-1]!=' ')
            return false;
    }
    if((end+1!=LT) && text[end+1]!=' ')
        return false;
    return true;
}

int main() {
    getline(cin,text);
    LP = pattern.size();
    LT = text.size();
    bool matchFound = false;
    for(int i=0,j=LP-1;j<LT;i++,j++) {
        if(match(i,j)) {
            matchFound = true;
            break;
        }
    }
    if(matchFound)
        cout << "YES";
    else
        cout << "NO";
}
