#include<iostream>
using namespace std;

void HelloWorld();

int main(int argc, char const *argv[])
{
    void (*ptr) () = &HelloWorld;
    (*ptr) ();
    return 0;
}

void HelloWorld(){
    cout<<"Hello world";
}