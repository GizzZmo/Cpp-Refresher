#include <iostream>
#include <string>
using namespace std;

class Test {
    private:
        string name;
    public :
        void setName(string nameParameter) {
            name = nameParameter;
        }
        string getName() {
            return name;
        }
};

int main() {
    Test test;
    test.setName("Amogh");
    cout<<test.getName();
    return 0;
}