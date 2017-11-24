#include <iostream>

using namespace std;

template<typename T>
int floor(T arr[], int n, T target)
{
    int l = 0;
    int r = n-1;
    while(l <= r)
    {
//         cout<<l<<" "<<r<<endl;
        int mid = l+(r-l)/2;
        if(arr[mid] == target)
        {
            if(mid > l)
            {
                if(arr[mid] != arr[mid-1])
                {
                    l = mid;
                    break;
                }
                else
                    r = mid-1;
            }
            else
                break;
        }
        if(arr[mid] > target)
            r = mid-1;
        if(arr[mid] < target)
            l = mid+1;
    }
    if(l<n && arr[l] == target) //should include condition "l<n"
        return l;
    else
        return l-1;
}

template<typename T>
int ceil(T arr[], int n, T target)
{
    int l = 0;
    int r = n-1;
    while(l <= r)
    {
//         cout<<l<<" "<<r<<endl;
        int mid = l+(r-l)/2;
        if(arr[mid] == target)
        {
            if(r > mid)
            {
                if(arr[mid] != arr[mid+1])
                {
                    r = mid;
                    break;
                }
                else
                    l = mid+1;
            }
            else
                break;
        }
        if(arr[mid] > target)
            r = mid-1;
        if(arr[mid] < target)
            l = mid+1;
    }
    if(r>=0 && arr[r] == target)    //should include condition "r>=0"
        return r;
    else
        return r+1;
}

int main()
{
    int a[] = {1, 1, 1, 2, 2, 2, 2, 2, 4, 4, 5, 5, 5, 6, 6, 6};
    int n = sizeof(a)/sizeof(int);
    for( int i = 0 ; i <= 8 ; i ++ ){

        int floorIndex = floor(a, n, i);
        cout<<"the floor index of "<<i<<" is "<<floorIndex<<".";
        if( floorIndex >= 0 && floorIndex < n )
            cout<<"The value is "<<a[floorIndex]<<".";
        cout<<endl;

        int ceilIndex = ceil(a, sizeof(a)/sizeof(int), i);
        cout<<"the ceil index of "<<i<<" is "<<ceilIndex<<".";
        if( ceilIndex >= 0 && ceilIndex < n )
            cout<<"The value is "<<a[ceilIndex]<<".";
        cout<<endl;

        cout<<endl;
    }
    
    return 0;
}