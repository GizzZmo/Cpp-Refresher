#include<iostream>
#include<vector>
using namespace std;

void MergeSort(int *, int);
void Merge(int *, int*, int ,int*, int);

int main(int argc, char const *argv[])
{
    int input[] = {9,2,7,4,1,8,3,6,10};
    MergeSort(input, sizeof(input)/sizeof(input[0]));
    for(auto num : input) {
        cout<< num << "\t";
    }
    return 0;
}

void MergeSort(int *arr, int size) {
    if(size < 2)
        return;
    
    int mid = size/2 ;

    int *left = new int[mid];
    int *right = new int[size-mid];

    for(int i=0;i<mid;i++) {
        left[i] = arr[i];
    }

    for(int i=mid;i<size;i++) {
        right[i-mid] = arr[i];
    }

    MergeSort(left, mid);
    MergeSort(right, mid);
    Merge(arr,left,mid,right,size-mid);

    delete left;
    delete right;
}

void Merge(int *A, int *leftPtr, int nL, int *rightPtr, int nR) {
    int i=0,j=0;
    int k=0;
    while(i<nL && j<nR) {
        if(leftPtr[i] < rightPtr[j]) {
            A[k] = leftPtr[i];
            i++;
        }
        else {
            A[k] = rightPtr[j];
            j++;
        }
        k++;
    }

    while(i<nL) {
        A[k++] = leftPtr[i++];
    }

    while(j<nR) {
        A[k++] = rightPtr[j++];
    }
}

