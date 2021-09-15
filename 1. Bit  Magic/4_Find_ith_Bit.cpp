#include<iostream>
using namespace std;
int main()
{
   int x,i;
   cout<<" Value in Decimal: ";
   cin>>x;
   cout<<" Input i value: ";
   cin>>i;
   int mask = 1<<i;
   x = x & mask;
   if(x&(1<<i))
   cout<<"NON ZERO"<<endl;
   else
   cout<<"ZERO was there"<<endl;
    return 0;

}
