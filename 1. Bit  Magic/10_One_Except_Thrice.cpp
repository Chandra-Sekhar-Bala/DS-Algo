#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> a{3,3,3,6,1,1,1,8,8,8};
    vector<int>::iterator i=a.begin()
    ;
	int n[32]={0};
	while(i<a.end())
    {

       for(int j=0; j<32; j++)
       {
       	  if((*i) & (1<<j))
       	   n[j]+=1;// to get all the set bits, which i can % with 3;
       	
       	// cout<<n[j]<<" ";
        }
       cout<<endl<<endl;
      i++;

    }

    // for(int j=0; j<32; j++)
    //    {
    //    	cout<<n[j]<<" ";
    //   }

    int res=0;
    for(int j=0; j<32; j++)
    {
    	n[j]%=3;// checking the number is one or not 
    	// cout<<n[j]<<" ";
    	res+=(n[j] * pow(2,j)); // Binary to decimal conversion
    }
 cout<<endl<<res<<endl;
 


	return 0;
}