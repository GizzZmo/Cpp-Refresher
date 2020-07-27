#include<iostream>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{
    int array[] = {74,-1,512,65,0};
    for(int i=0;i<sizeof(array)/sizeof(array[0])-1; i++) {
        int min = INT_MAX;
        int pos = i;
        for(int j=i+1; j<sizeof(array)/sizeof(array[0]); j++) {
            if(array[j]<min) {
                pos = j;
                min = array[j];
            }
        }
        swap(array[i], array[pos]);
    }
    cout << "Sorted array : "<< endl;
    for(auto x : array) {
        cout << x << "\t";
    }
    return 0;
}
