#include<iostream>
int ModuloA(int a,int b)
{
    int res = 1;
    while(! ( b & 1 ))
    {
     res*=a;
    a = a * a;
    b = b >> 1;
     }
     return res;
}
int main()
{
    int b,n;
    std:: cin>>n>>b;
    std::cout<<ModuloA(n,b);
}