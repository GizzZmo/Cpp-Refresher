#include<iostream>
#include<array>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout << "address of a[i]th element ="<<  arr+i << endl;
        cout<< "value of a[i] = "<< *(arr + i)<<endl;
    }
    cout<< "arr value = " << arr<< endl;
    cout<< "sizeof arr = "<< sizeof(arr) << endl;
    return 0;
}
