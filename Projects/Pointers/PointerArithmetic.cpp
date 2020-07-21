#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int number[] = {1,2,3};
    int *p = number;
    int *q = number+1;
    cout<< p <<endl;
    cout << q <<endl;
    cout << q-p<<endl;
    return 0;
}
