#include<bits/stdc++.h>
using namespace std;
// Chech is that position is afe or not?
bool isSafe(int **a, int n, int row, int col)
{
  int r=row;
  int c=col;
  // checkign 0 - that [row] [col]
   for(int i=0;i<row;i++ )    
  {
    if(a[i][col]==1)
    return false;
  }
  // cheking right diagonal
  while(r>=0 &&  c>=0)
  {
    if(a[r][c]==1){
    return false;
  }
   r--;
   c--;
  }
  r=row; 
  c=col;
  // checking left diagonal
  while(r>=0 && c<n)
  {
    if(a[r][c]==1)
    return false;
    r--;
    c++;
  }
  return true;
}
//return true if it's possible
bool nQueen(int **a,int n, int row)
{
  if(row >= n)
  return true;

  for(int col=0; col<n; col++)
  {
    if(isSafe(a,n, row, col)){
    a[row][col]=1;

    if(nQueen(a,n,row+1))
    return true;

    a[row][col]=0;
    }
  }
  return false;
}


// Driver code:
int main()
{
int n;
cin>>n;
// creating n size array of pointers 
int** a=new int*[n];
for(int i=0; i<n; i++)
{
  a[i]=new int [n];// creating n size int block and pointing to each array of pointers
  for(int j=0; j<n; j++)
  {
    a[i][j]=0;
  }
}
// if true ony then print
if(nQueen(a,n,0)){
for(int i=0; i<n; i++)
{
  for(int j=0; j<n; j++)
  {
    cout<<a[i][j]<<" ";
  }
  cout<<endl;
}
}
else
cout<<"Isn't Possible"<<endl;
return 0;

}


/*bool nQueen(int a[][],int N, int row)
{
 if(row==N)
 return true;
 for(int col=0,col<N; col++)
 {
    if(isSafe(a,N,row,col)
    { 
      a[row][col]=true;
      if(nQueen(a,N,row+1))
      return true;
    // <--if next is valid then it'll return from here-->
       a[row][col]=false;//  <--BACKTRACK-->
     }    
 }
}*/