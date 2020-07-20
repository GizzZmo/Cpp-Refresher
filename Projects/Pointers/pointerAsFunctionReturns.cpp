#include<iostream>
using namespace std;

int* add(int *, int*);

int main(int argc, char const *argv[])
{
    int a =10, b=12;
    int *ptr = add(&a, &b); 
    cout<< *ptr;
    return 0;
}

int* add(int *ptrA, int* ptrB) {
    int c = *ptrA + *ptrB;
    return &c;
}