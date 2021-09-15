// set 1 to i'th position
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i;
    cin>>i;
    int mask=~(1<<i);
    n=n & mask;
    cout<<n<<endl;

    return 0;
}