#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    ofstream fileObject;
    fileObject.open("testFile.txt");
    fileObject << "I can do it";
    fileObject.close();
    return 0;
}
