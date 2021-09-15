#include<iostream>
using namespace std;
void printpowerSet(string s,int i,string curr)
{
    //1. Base Case: Untill iterator!=s.legth();
    //2. Relation btwn problem & sub Problem: Addinng a char. and not adding a char
    //  3. Generalized solution is:

    if(i==s.length())
    {
        cout<<curr<<endl;
        return ;
    }
    printpowerSet(s, i+1, curr+s[i]);
    printpowerSet(s,i+1, curr);
    // return ;
}
       
int main()
{
    string s;
    cin>>s;
    printpowerSet(s,0," ");
}

