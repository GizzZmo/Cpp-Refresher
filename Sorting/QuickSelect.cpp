#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&, int , int);

int main(int argc, char const *argv[])
{
    vector<int> input  = {7, 10, 4, 3, 20, 15};
    int low = 0;
    int high = input.size()-1;
    int kthlargest = 1;
    int k = input.size()+1-kthlargest;
    while(low<high) {
        int pivotIndex = partition(input, low, high);
        cout << "PI : "<< pivotIndex <<endl;
        if(k-1<pivotIndex){
            high = pivotIndex-1;
        }
        else if(k-1>pivotIndex){
            low = pivotIndex+1;
        }
        else {
            break;
        }
    }
    cout << input[k-1];
    return 0;
}

int partition(vector<int>&nums, int low, int high) {
    int i=low-1;
    int j=low;

    while(j<high) {
        if(nums[high]>=nums[j]) {
            swap(nums[++i],nums[j++]);
        }
        else {
            j++;
        }
    }
    swap(nums[++i],nums[high]);
    for(auto num :nums) {
        cout << num << "\t";
    }
    cout << "I : " << i <<endl;
    return i;
}