#include <iostream>
#include "minHeap.h"

using namespace std;

template<typename T>
void heapSort(T arr[], int n) {
    MinHeap<int> minHeap = MinHeap<int>(n);
    for(int i=0; i<n; i++)
        minHeap.insert(arr[i]);
    for(int i=0; i<n; i++)
        arr[i] = minHeap.extractItem();
}

int main() {
    int arr[10] = {10, 9, 8, 7, 5, 4, 6, 3, 1, 2};
    heapSort(arr, 10);
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}