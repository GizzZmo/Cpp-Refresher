#include<iostream>
using namespace std;

int BinarySearch(int*, int, int , int);

int main(int argc, char const *argv[])
{
    int mainArray[] = {1,2,3,4,56,73576};
    int searchEle = 73576;
    BinarySearch(mainArray, searchEle, 0, sizeof(mainArray)/sizeof(mainArray[0])-1) ? cout<<"Element present" : cout<< "Element absent";
    return 0;
}
 
int BinarySearch(int *Arr, int ele, int start, int end) {
    if(start>end)
        return 0;
    int mid = end - (end - start)/2;
    if(Arr[mid]==ele) {
        return 1;
    }
    else if(Arr[mid]>ele) {
        return BinarySearch(Arr, ele, start, mid-1);
    }
    else {
        return BinarySearch(Arr, ele, mid+1, end);
    }
}