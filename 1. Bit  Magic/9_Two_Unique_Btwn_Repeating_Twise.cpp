#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> a{3,2,1,9,8,1,2,3};
    vector<int>::iterator i=a.begin();
	int res1=0;
	int res2=0;
	while(i<a.end())
	{
		if((*i) & 1)
          res1^=(*i);
	    else
	      res2^=(*i);
	  
	  i++;
	}
	cout<<res1<<" "<<res2<<endl;
	
}