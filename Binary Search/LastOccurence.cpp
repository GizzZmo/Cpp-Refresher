#include<iostream>
using namespace std;

int LastOccurence(int *, int, int, int, int);

int main(int argc, char const *argv[])
{
    int mainArray[] = {1,2,3,3,3,4,4,4,4, 1000, 1200};
    int searchEle = 4;
    int present = LastOccurence(mainArray, 0,  sizeof(mainArray)/sizeof(mainArray[0])-1, searchEle, -1) ;
    (present!=-1) ? cout<<"Element's last occurence : " <<  present : cout<< "Element absent";
    return 0;
}
 
int LastOccurence(int *Arr, int start, int end, int ele, int lastOccurence) {
    if(start>end) {
        return lastOccurence;
    }
    int mid = start + (end-start)/2;
        if(Arr[mid] == ele) {
            lastOccurence = mid;
            return LastOccurence(Arr, mid+1, end, ele, lastOccurence);
        }
        else if(Arr[mid] > ele) {
            return LastOccurence(Arr, start, mid-1, ele, lastOccurence);
        }
        else {
            return LastOccurence(Arr, mid+1, end, ele, lastOccurence);
        }
}