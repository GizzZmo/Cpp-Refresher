#include <iostream>
using namespace std;

class TestClass{
    public:
        TestClass();
        void printSomething();
        ~TestClass();
};

TestClass::TestClass() {
    cout<< "Inside the constructor" << endl;
}
void TestClass::printSomething() {
    cout<< "Something";
}

TestClass::~TestClass() {
    cout<< "Inside the deconstructor" << endl;
}