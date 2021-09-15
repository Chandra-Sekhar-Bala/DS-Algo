#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    // cout<<t&1;
    // t=t&1;
    if(!(t&1))
    cout<<" Even Number ";
    else
    cout<<" ODD Number" ;
    
    return 0;
}