#include<iostream>
using namespace std;
void Merge(int a[], int l, int mid, int r)
{
    //cout<<"inside MERGE  "<<endl<<endl;;
    int n1 = mid - l +1;
    int n2 = r- mid;

    // Dividing main array in 2 part
    int  t1[n1],t2[n2];

    //  Taking upto mid array in t1
    for(int i=0; i<n1; i++){
        t1[i] = a[l+i];
    }

   // Taking mid to Last array in t2
    for(int i = 0; i<n2; i++){
        t2[i] = a[mid+i+1];
    }

// Declaring Iterators:-
    int i=0,j=0;
    int it =l;
    // Main Sorting
    while(i<n1 && j<n2)
    {
        if(t1[i] > t2[j])
        {
            a[it] = t2[j];
            it++;
            j++;
        }
        else{
            a[it] = t1[i];
            it++;
            i++;
        }
    }
    // if j become 0 but i not finished
    while(i<n1)
    {
        a[it] = t1[i];
        it++;
        i++;
    }

    // if i become 0 but j not finished
    while(j < n2)
    {
        a[it] = t2[j];
        it++;
        j++;
    }

}
void MergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int mid =(l+r)/2;
        MergeSort(a, l, mid);
        MergeSort(a,mid+1,r);

        Merge(a, l, mid, r);
    }
}


int main()
{
    int n = 5;
    cin >> n;
    int a[n];
     for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }


    MergeSort(a,0,n);
     for(int i=0; i<n; i++)
    {
        cout << a[i]<<" ";
    }
}
