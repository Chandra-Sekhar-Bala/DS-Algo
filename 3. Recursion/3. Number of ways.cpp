#include<iostream>
using namespace std;
int ways(int r, int c)
{
    if(r==1 || c==1)
    return 1;
    // Resursion: I'm giving yout r-1 and c-1 's solution can you solve for the whole matrix?
    // Me: Oh yeah whay not, I'll add those reasult and here we got the answer :-)
    return (ways(r-1,c) + ways(r,c-1));
}
int main()
{
    int r,c;
    cin>>r>>c;
    cout<<ways(r,c)<<endl;
    return 0;
}