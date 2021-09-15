#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    a=a^b;
    b^=a;
    a^=b;
    cout<<"A:"<<a<<endl;
    cout<<"B:"<<b<<endl;
    return 0;

}