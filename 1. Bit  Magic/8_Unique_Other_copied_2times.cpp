#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,4,3,2,1};
    int res=0;
    int i=0;
    while(i<6)
    {
        res= res ^ a[i++];
    }
    cout<<" Answer is:"<<res<<endl;
    return 0;
}
