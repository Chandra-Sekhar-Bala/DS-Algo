#include<iostream>
using namespace std;
/*
TODO: Repeatly swap two adjacent element if they are inn wrong order:
*/
int main()
{
   int n;
   cin >> n;


   int a[n];

   for(int i=0; i<n; i++){
    cin >> a[i];
   }

    cout<< endl;

    for(int i=0 ; i<n; i++)
    {
        for(int j=0; j< n-i; j++)
        {
            if(a[j] > a[j+1] )
            {
                swap(a[j], a[j+1]);
                }
        }
    }

     for(int i=0; i<n; i++){
     cout << a[i]  <<" ";
     }
     return 0;

    }

