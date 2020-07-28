#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int array[]={7,4,5,2};
    for(int i=1; i<sizeof(array)/sizeof(array[0]);i++) {
        int temp = array[i];
        int pos = i;
        while(pos>=1 && array[pos-1]>temp){
            array[pos] = array[pos-1];
            pos--;
        }
        array[pos] = temp;
        cout << i << "th iteration"<<endl;
        for(auto x : array) {
            cout << x << "\t";
        }
        cout << endl;
    }
    cout<< "Sorted array : "<<endl;
    for(auto x : array) {
        cout << x << "\t";
    }
    return 0;
}
