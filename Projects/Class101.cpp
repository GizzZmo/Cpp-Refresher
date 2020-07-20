#include <iostream>

using namespace std;

class FirstClass{
    public:
        void coolSomething() {
            cout << "Hi";
        }
}; 

int main() {
    FirstClass fclass;
    fclass.coolSomething();
    return 0;
}