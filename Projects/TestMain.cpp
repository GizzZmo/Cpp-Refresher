#include <iostream>
#include "ScopeResolution1.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    TestClass testClass;
    // testClass.printSomething();

    // TestClass *classPointer = &testClass;
    // classPointer->printSomething();
    cout<<"Inside the main method"<< endl;

    return 0;
}
