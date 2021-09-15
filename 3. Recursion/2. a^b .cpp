#include<iostream>
using namespace std;
long int power(int a, int b)
{
    if(!b)
    return 1;

    return (a* power(a,b-1));
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<power(a,b);
    return 0;
}