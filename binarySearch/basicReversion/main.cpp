#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
int __search(T arr[], int l, int r, T target)
{
    if(l > r)
        return -1;  //target not found!!!
    int mid = l+(r-l)/2;    //compare with expression "mid = (r+l)/2", avoid data overflow
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] > target)
        return __search(arr, l, mid-1, target);
    else
        return __search(arr, mid+1, r, target);
}

template<typename T>
int binarySearch(T arr[], int n, T target)
{
    assert(n > 0);
    //assert(isSorted(arr, n));
    return __search(arr, 0, n-1, target);
}

int main()
{
    int arr[10] = {1, 2, 3, 3, 4, 5, 6, 6, 7, 8};
    cout<<binarySearch(arr, 10, 5)<<endl;
    cout<<binarySearch(arr, 10, 9)<<endl;
    return 0;
}