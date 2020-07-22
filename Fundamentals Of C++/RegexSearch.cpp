#include<iostream>
#include<regex>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    regex r("c*d+e");
    string var = "aabbcddddeasdasde";
    smatch m;
    regex_search(var, m,r );
    cout<<m[0]<<endl;
    return 0;
}
