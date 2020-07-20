#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    const regex r("a(b*)(c+)d");
    string s = "abbbccd";
    smatch m,t;
    bool b = regex_match(s, m, r);
    cout << m[1] << endl;
    cout << m[2] << endl;
    const regex da("(\\d{2})/(\\d{4})");
    string date = "05/1994";
    bool y = regex_match(date, t,  da);
    cout<<t[1]<<endl;
    cout<<t[2]<<endl;
    return 0;
}
