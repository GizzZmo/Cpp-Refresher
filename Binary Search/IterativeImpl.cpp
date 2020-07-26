#include<iostream>
#include<array>
using namespace std;

int BinarySearch(int *, int, int);

int main(int argc, char const *argv[])
{
    int mainArray[] = {1,2,3,4,56,73576};
    int searchEle = 73576;
    BinarySearch(mainArray, sizeof(mainArray)/sizeof(mainArray[0]), searchEle) ? cout<<"Element present" : cout<< "Element absent";
    return 0;
}
 
int BinarySearch(int *Arr, int size, int ele) {
    int start = 0;
    int end = size-1;
    while(start<=end) {
        int mid = end - (end-start)/2;
        if(Arr[mid] == ele) {
            return 1;
        }
        else if(Arr[mid] > ele) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return 0;
}