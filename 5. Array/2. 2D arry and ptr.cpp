#include<iostream>
using namespace std;
int main()
{
    int a[][3]={{1,3,3},{4,5,6},{7,8,9}};
    int (*p)[3]=a;
    cout<<"a "<<a<<endl;
    cout<<**p<<endl;
    cout<<"**p "<<**p<<endl;
    cout<<"*(p+1) "<<*(p+1)<<endl;
    cout<<"*(*(p+1)+1) "<<*(*(p+1)+1)<<endl;
    cout<<p[0][0]<<endl;
    cout<<"**(p++) "<<**++p<<endl;
    cout<<**p<<" "<<p[0][0];
    return 0;
}