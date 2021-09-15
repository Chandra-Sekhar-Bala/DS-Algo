#include<iostream>
using namespace std;
int fact(int n)
{
/* Recursion: I'm giving you 'n-1' nos factorial can you solve for the  n's ?
 Me: Oh yeah why not, I'll multiply my 'n' and your 'n-1' solution, and here we got the answer ;-)
   <!-->

1. Base Case: Untill n!=0;
2. Relation btwn problem & sub Problem: multiply n with n-1's factorial;
3. Generalized solution is:*/

    if(!n)
    return 1;
    return (n * fact(n-1));
    
}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
}