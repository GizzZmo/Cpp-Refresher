#include <iostream>
using namespace std;

int x = 42;
int main(int argc, char const *argv[])
{
    int x = 4;
    cout<< ::x;
    return 0;
}
