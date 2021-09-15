#include<iostream>
using namespace std;
int Partition(int a[], int l, int r){
	int piv = a[r];
	int i=l-1;
	for(int j = l; j < r; j++ ){

		if(a[j]  < piv)
		{
			i++;
			swap( a[i], a[j]);
		}
	//after this loop i will be pointing that index which is most smaller then pivert element:
	}
	swap(a[i+1], a[j-1]);
	return i+1;
}
void QuickSort(int a[], int l, int r){
	if(l<r)
	{
		int p = Partition(a,l,r);

		QuickSort(a,l,p-1);
		QuickSort(a,p+1,r);

	}
}
int main()
{
	cout<<"Enter the array"<<endl; 
	int n;
	cin >> n;
	int a[n];
	for(int i =0; i< n; i++)
		cin >> a[i];
	QuickSort(a,0,n);
	for(int i =0; i< n; i++)
		cout << a[i];
	

}