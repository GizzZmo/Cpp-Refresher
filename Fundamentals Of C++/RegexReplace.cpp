#include<iostream>
#include<regex>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    regex r("c+d*e");
    string s = "sceaccdddeeasdacde";
    string replacement = "TADA";
    cout<< regex_replace(s,r,replacement);
    return 0;
}
