#include<iostream>
using namespace std;
int main()
{
    int a[]={1,3,3,4,5};
    int *p;
    p=a;
    cout<<"a "<<a<<endl;
    cout<<"&a "<<&a<<endl;
    cout<<"*a "<<*a<<endl;
    cout<<"*(a+1) "<<*(a+1)<<endl;
    cout<<"*a+1 "<<*a+1<<endl;
    cout<<"*p "<<*p<<endl;
    cout<<"*p+1 "<<*p+1<<endl;
    cout<<"*(p+1) "<<*(p+1)<<endl;
    cout<<"*(p++) "<<*(p++)<<endl;
    cout<<*p;

    return 0;
}