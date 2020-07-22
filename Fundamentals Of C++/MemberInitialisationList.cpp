#include<iostream>
using namespace std;

class MemberInit{
    public:
        MemberInit(int regVal, int constVal);
        void printValues();
    private:
        int regVar;
        const int constVar; 
};

MemberInit::MemberInit(int firstRegVal, int secConstVal)
: regVar(firstRegVal),
constVar(secConstVal)
{
}

void MemberInit::printValues(){
    cout<< "Value of regVar : " << regVar <<endl;
    cout<< "Value of const var: "<< constVar;
}

int main(int argc, char const *argv[])
{
    MemberInit mem(7,8);
    mem.printValues();
    return 0;
}
