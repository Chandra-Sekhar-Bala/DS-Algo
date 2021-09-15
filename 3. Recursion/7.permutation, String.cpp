#include<bits/stdc++.h>
using namespace std;
//code isn't complete right now cz I'm frstrated right now af 
void permute(string s, int i, int j)
{
  if(i==j)
  {
    cout<<s<<endl;
    return ;
  }
  for(int r=i; r<=j; r++)
  {
    swap(s[i],s[r]);
    permute(s,i+1,j);
    swap(s[i],s[r]);
  }
  return ;
}
int main()
{
  string s;
  cin>>s;
  permute(s,0,s.length());
  return 0;
}