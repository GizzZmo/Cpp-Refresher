#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream readFile("fileWritten.txt");
    string line;
    while(getline(readFile, line)){
        cout<< line << endl;
    }
    return 0;
}
