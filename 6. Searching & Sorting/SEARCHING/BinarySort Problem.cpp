#include<iostream>
using namespace std;
int bienerySort(int a[],int key,int l, int r)
{
	// TRaditional Binary search
	while(l <= r)
	{
		int mid = (l + r)/2;
		if(a[mid] < key)
		l=mid+1;
		else if(a[mid] > key)
	 	r = mid-1;
		else
		return mid;
	}
	return -1;
}
void boundery(int a[],int index, int key, int l, int r){

// 1st case when index found
	 if(a[index] == key)
	{
		if(index == 0 || index == r)
		{
			if(index == 0 ){
		    cout<<-1<<" "<<a[index+1];
			if(index == r)
		    cout<<a[index-1]<<" "<<-1;
			return ;
		}
		else
		cout << a[index-1]<<" "<<a[index+1];
	}
	//2nd case when index desen't found
	else{

	int mid;
		while(l <= r)
	 {
		 mid = (l + r)/2;
		if(a[mid] < key)
		l=mid+1;
		else if(a[mid] > key)
		r = mid-1;
	 }
		cout<<a[mid+1]<<" "<<a[mid+1];
		return ;
  }

}
}

int main()
{
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	cin>>a[i];
	 sort(a,a+n-1);
	int q;
	cin>>q;

	while(q--)
	{

	   // cout<<"Q = "<<q<<endl;
		int x;
		cin>> x;
		// sort(arr, arr + n);
		int index = bienerySort(a,x,0,n-1);
		if(index!=-1){
			cout<<"YES ";
			boundery(a,x,index,0,n-1);
		}
		else{
			cout<<"NO ";
			boundery(a,x,index,0,n-1);
		}

		cout<<endl;
	}

}
