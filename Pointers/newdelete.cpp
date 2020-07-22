#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int *p = new int;
    *p = 10;
    cout<< "Address held by p "<< p <<endl;
    delete p;
    return 0;
}
