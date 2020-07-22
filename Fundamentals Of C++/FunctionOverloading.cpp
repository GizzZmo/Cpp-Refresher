#include<iostream>
using namespace std;

void printNumber(int);
void printNumber(float);

int main(int argc, char const *argv[])
{
    int a = 2;
    float b = 4.121;
    printNumber(a);
    printNumber(b);
    return 0;
}

void printNumber(int a ){
    cout<<"Function overloading for int number "<< a <<endl;
}

void printNumber(float b ){
    cout<<"Function overloading for float number "<< b <<endl;
}
