#include<iostream>
using namespace std;
bool palS(string s,int i, int j)
{ 
    //1. Base Case: Untill 1st iterator !>= last iterator;
    //2. Relation btwn problem & sub Problem: check 1st_char!=last_char if yes->then remove 1st and last char 
    //  3. Generalized solution is:
    
    if(i>=j)
    return true;
    // cout<<"' if"<<endl;
     if(s[i]!=s[j])
     return false;
     else
     return palS(s,i+1,j-1);

}
int main()
{
    string s;
    cin>>s;
    if(palS(s,0,s.size()-1))
    cout<<" Palindrome";
    else
    cout<<" False"<<endl;
    return 0;
}