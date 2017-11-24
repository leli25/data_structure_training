#include <iostream>

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target)
{
    int l = 0;
    int r = n-1;
    while(l <= r)
    {
        int mid = l+(r-l)/2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] > target)
            r = mid-1;
        if(arr[mid] < target)
            l = mid+1;
    }
    return -1;
}

int main()
{
    int arr[10] = {1, 2, 3, 3, 4, 5, 6, 6, 7, 8};
    cout<<binarySearch(arr, 10, 5)<<endl;
    cout<<binarySearch(arr, 10, 9)<<endl;
    return 0;
}