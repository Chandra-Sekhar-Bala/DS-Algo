#include<iostream>
using namespace std;
int main()
{
   int n=5;
    int **p = new int * [n];

    for(int i=0; i<n; i++)
    {
      p[i]=new int [n];
        for(int j=0; i<n; j++)
        {
        p[i][j] = 10 * (i+j); // p[i][j] = 10df df*(i+j);
        }
    }
    // cout<<*p<<endl;
    // cout<<**p<<endl;
    // cout<<*p+1<<endl;
    // cout<<**p+1<<endl;
    // cout<<*(*(p+1)+0)<<endl;
    // cout<<p[3][3]<<endl;
    return 0;
}