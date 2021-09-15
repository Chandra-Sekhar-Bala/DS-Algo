#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x=n;
    int res=0;
    while(n)
    {
        res=(res * 10)+(n%10);
        n/=10;
    }
    if(x==res){
    cout<<"Okay";
      }
        else
         cout<<" NOT okk";
    return 0;
}