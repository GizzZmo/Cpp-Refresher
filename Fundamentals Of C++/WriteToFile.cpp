#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    ofstream fileOutputStream("fileWritten.txt");
    if(fileOutputStream.is_open()){
        fileOutputStream<< "Blah blah blah"<<endl;
        fileOutputStream<< "FIrst blah blah"<<endl;
        fileOutputStream<< "Sec blah blah"<<endl;
        fileOutputStream<< "THird blah blah"<<endl;
    }
    fileOutputStream.close();
    return 0;
}
