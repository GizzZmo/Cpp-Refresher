#include<iostream>
using namespace std;

int Search(int *, int, int);

int main(int argc, char const *argv[])
{
    int mainArray[] = {12,14,18,21,3,6,8,9};
    int ele = 9;
    int index = Search(mainArray, sizeof(mainArray)/sizeof(mainArray[0]), ele) ;
    index!=-1 ? cout <<"present at : " << index : cout<<"not present";
    return 0;
}
 
int Search(int *Arr, int size, int ele) {
    int start = 0;
    int end = size-1;
    while(start<=end) {
        int mid = start + (end-start)/2;
        if(Arr[mid]==ele) {
            return mid;
        }
        else if(Arr[mid]<=Arr[end]) {
            if(ele>Arr[mid] && ele<=Arr[end]){
                start=mid+1;
            }
            else {
                end = mid-1;
            }
        }
        else if(Arr[start]<=Arr[mid] ) {
            if(ele>=Arr[start] && ele<Arr[mid]) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
    }
    return 0;
}
