#include<iostream>
using namespace std;

int FirstOccurence(int *, int, int);

int main(int argc, char const *argv[])
{
    int mainArray[] = {1,2,3,3,3,4,4,4,4, 1000, 1200};
    int searchEle = 4;
    int present = FirstOccurence(mainArray, sizeof(mainArray)/sizeof(mainArray[0]), searchEle) ;
    (present!=-1) ? cout<<"Element's first occurence : " <<  present : cout<< "Element absent";
    return 0;
}
 
int FirstOccurence(int *Arr, int size, int ele) {
    int start = 0;
    int end = size-1;
    int firstOccurence=-1;
    while(start<=end) {
        int mid = end - (end-start)/2;
        if(Arr[mid] == ele) {
            firstOccurence = mid;
            end = mid-1;
        }
        else if(Arr[mid] > ele) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return firstOccurence;
}