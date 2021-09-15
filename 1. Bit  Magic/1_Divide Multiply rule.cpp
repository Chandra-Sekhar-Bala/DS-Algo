#include<iostream>
using namespace std;
int main()
{

int x;
cin>>x;
int a=x>>1;
int b=x<<1;
cout<<"Normalllt x is: "<<x<<" right shift - divide rule: "<<a<<endl;
cout<<"Normalllt x is: "<<x<<" right shift - multiply rule: "<<b<<endl;
while(x){
int n=x>>1;
cout<<x<<" ",
x>>=1;
}

}
