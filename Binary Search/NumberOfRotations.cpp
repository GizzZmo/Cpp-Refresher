#include<iostream>
using namespace std;

int Rotations(int *, int);

int main(int argc, char const *argv[])
{
    int mainArray[] = {3,5,8,11,12,2};
    cout<<"Number of rotations: "<< Rotations(mainArray, sizeof(mainArray)/sizeof(mainArray[0])) ;
    return 0;
}
 
int Rotations(int *Arr, int size) {
    int start = 0;
    int end = size-1;
    while(start<=end) {
        if(Arr[start]<=Arr[end]) {
            return start;
        }
        int mid = start + (end-start)/2;
        if(Arr[mid] > Arr[mid+1])
        {
            return mid+1;
        }
        if(Arr[mid] <  Arr[end]) {
            end=mid;
        }
        else {
            start = mid;
        }
    }
    return 0;
}
