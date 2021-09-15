#include <iostream>
using namespace std;
/*
Todo: Insert an element from unsorted array to it's correct position in sorted array:
if we're in i'th element, i-1'th element should be < lesser and i+1'th element should be greater >
*/

void insertionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        //I've to check temp which is a[i] with a[i-1];
        int j = i - 1;
        while (a[j] > temp && j >= 0)
        {
            a[j + 1] = a[j];
        //simply swaping cz these are greater than my temp;
            j--;
        }
        // after that loop j will be pointing that index which is less then temp;
        a[j + 1] = temp;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertionSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}