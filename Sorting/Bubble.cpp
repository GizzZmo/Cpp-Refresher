#include<iostream>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{
    int array[] = {74,-1,512,65,0};
    for(int i=0;i<sizeof(array)/sizeof(array[0]); i++) {
        bool flag = false;
        for(int j=0; j+1<sizeof(array)/sizeof(array[0])-i; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
                flag = true;
            }
        }
        if(!flag) {
            break;
        }
    }
    cout << "Sorted array : "<< endl;
    for(auto x : array) {
        cout << x << "\t";
    }
    return 0;
}