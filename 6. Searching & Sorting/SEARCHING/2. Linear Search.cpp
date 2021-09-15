#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i< n; i++)
    cin >> a[i];
    int key;
    cout<< "Find what?"<<endl;
    cin >> key;

    for(int i=0; i<n; i++){
    	cout<<i<<endl;
        if(a[i] == key)
        {
            cout<<"Found "<<key << " at Position "<<i+1<< endl;
            return 0;
        }
    }
    return 0

}
