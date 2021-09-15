// set 1 to i'th position
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i;
    cin>>i;
    n|=1<<i;
    cout<<n;

    return 0;
}