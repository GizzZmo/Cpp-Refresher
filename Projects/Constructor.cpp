#include <iostream> 
#include <string>
using namespace std;

class Constructor{
    public:
        void setName(string nameParameter) {
            name = nameParameter;
        }
        string getName() {
            return name;
        }
        Constructor(string nameParameter) {
            setName(nameParameter);
        }
    private:
        string name;
};

int main() {
    Constructor newConstructor("Amogh");
    cout << newConstructor.getName();
    return 0;
}