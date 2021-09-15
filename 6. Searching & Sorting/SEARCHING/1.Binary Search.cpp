#include<iostream>
using namespace std;
int BinarySearch(int a[], int key, int l, int r)
{
    while(l<=r)
    {
        // cout<<l<<" +"<<r<<" = ";
        int mid = (l+r)/2;
        if(a[mid] == key)
        {
            return mid;
        }
        else if(a[mid] > key)
        {
            r = mid-1;
        }
        else
        {

            l = mid+1;
        }
    }
    return -1;
}
int main()
{
    int a[]={1,1,4,5,5,7,9};
    int key = 4;
    // cin>>key;
    cout<<BinarySearch(a,key,0,7);
    return 0;
}
