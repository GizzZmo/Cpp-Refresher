#include <iostream>
using namespace std;

void printArrayElements(int array[], int sizeOfTheArray);

int main(int argc, char const *argv[])
{
    int arr[3] = {1,2,3};
    printArrayElements(arr, 3);
    return 0;
}

void printArrayElements(int array[], int size) {
    for(int i=0; i<size; i++) {
        cout << array[i] << "\n" ;
    }
}
