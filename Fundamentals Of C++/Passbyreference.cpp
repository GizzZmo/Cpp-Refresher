#include<iostream>
using namespace std;

void IncrementedNumber(int *pointerToInt);

int main(int argc, char const *argv[])
{
    int x = 12;
    IncrementedNumber(&x);
    cout<< x;
    return 0;
}

void IncrementedNumber(int *pointerVar){
    *pointerVar += 1;
}
