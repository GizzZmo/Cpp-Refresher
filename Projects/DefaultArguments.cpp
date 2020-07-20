#include <iostream>
using namespace std;

int area(int length=1, int breadth=2);

int main() {

    cout<< area();
    return 0;
}

int area(int length, int breadth) {
    return length * breadth;
}
