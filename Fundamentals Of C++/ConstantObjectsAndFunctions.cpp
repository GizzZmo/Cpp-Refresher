#include<iostream>
using namespace std;

class Test{
    public:
        void something();
        void constsomething() const;
};
void Test::something(){
    cout<< "Something"<<endl;
}

void Test::constsomething() const{
    cout<< "Inside const funciton"<<endl;
}

int main(int argc, char const *argv[])
{
    Test test;
    test.constsomething();
    test.something();

    const Test test2;
    test2.constsomething();

    return 0;
}
