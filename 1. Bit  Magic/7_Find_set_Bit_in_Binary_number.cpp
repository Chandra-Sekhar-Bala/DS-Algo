#include<iostream>
using namespace std;
int main()
{
    int n
;
cin>>n;
int count=0;
/*while(n)
{
    if(n&1)
    count++;
    n>>=1;
}
cout<<"Nmbers of set bits are: "<<count<<endl;*/

//optmized SOLn
while(n)
{
    count++;
    n&=n-1;
}
cout<<"Nmbers of set bits are: "<<count<<endl;

    return 0;
}