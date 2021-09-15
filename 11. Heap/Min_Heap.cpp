#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int capacity;
    int *arr;
    int size;
    heap()
    {
        size = 1;
        capacity = 0;
        arr = NULL;
    }

    heap(int data)
    {
        size = 0;
        this->capacity = data;
        arr = new int[data];
    }

    heap(heap &root)
    {
        capacity = root.capacity;
        size = root.size;
        this->arr = new int[capacity];
        for (int i = 0; i < root.size; i++)
            arr[i] = root.arr[i];
    }

    int getMin()
    {
        return arr[0];
    }
    int getMax()
    {
        return arr[size - 1];
    }

    int left(int i)
    {
        return (2 * i) + 1;
    }

    int right(int i)
    {
        return (2 * i) + 2;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void swap(int &x, int &y)
    {
        int t = x;
        x = y;
        y = t;
    }
    void insert(int data)
    {
        if (size <= 0)
        {
            arr[size] = data;
            size++;
            return;
        }
        size++;
        int i = size - 1;
        arr[i] = data;

        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    // Restructure the array:
    void min_heapify(int i)
    {
        // cout << "i: "<< i <<" arr: "<<arr[i]<<" size: "<<size<<endl;
        if (size <= 0 || size == 1)
        {
            return;
        }

        int l = left(i);
        int r = right(i);
        int smallest = i;

        // if l,r is the leaf node we desen't have to re-structure ;
        if (l < size && arr[i] > arr[l])
        {
            smallest = l;
            if (r < size && arr[r] < arr[l])
                smallest = r;
        }
        // else
        // smallest = l;

        if (r < size && arr[i] > arr[r])
        {
            smallest = r;
            if (arr[r] > arr[l])
                smallest = l;
        }
        // cout<<"Size "<<size << " smllest " << smallest <<" val"<< arr[smallest] << endl;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            // int temp = arr[i];
            // arr[i] = arr[smallest];
            // arr[smallest] = temp;
            min_heapify(smallest);
        }
        return;
    }

    // root will be exctracted and then heapify()

    int extractMin()
    {
        if (size <= 0)
        {
            return INT_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        int temp = arr[0];
        arr[0] = arr[size - 1];
        size--; // size -1 element does't exist now
        min_heapify(0);
        return temp;
    }

    int search(int x)
    {
        for (int i = 0; i < size; ++i)
        {
            if (arr[i] == x)
                return i;
        }
        return -1;
    }
    /*  void decreseKey(int x)
    {
        arr[x] = INT_MIN;

        // until we sort 0'th index
        while (x != 0 && arr[parent(x)] > arr[x])
        {
             int temp = arr[x];
         arr[x] = arr[parent(x)];
         arr[parent(x)] = temp;
            // swap(arr[parent(x)], arr[x]);
            x = parent(x);
        }
    }*/

    void deletekey(int key)
    {
        int index = search(key);
        if (index == -1)
            return;
        arr[index] = arr[size - 1];
        size--;
        min_heapify(index);

        // while (index!=0 &&  arr[parent(index)] > arr[index])
        // {
        //      int temp = arr[index];
        //      arr[index] = arr[parent(index)];
        //      arr[parent(index)] = temp;
        //     // swap(arr[parent(x)], arr[x]);
        //     index = parent(index);
        // }

        // decreseKey(index);
        // extractMin();
    }

    void print()
    {
        if (size <= 0)
        {
            cout << "No element" << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    int find(int x)
    {
        for (int i = 0; i < size; ++i)
        {
            if (arr[i] == x)
                return 1;
        }
        return 0;
    }

    void HeapSort()
    {
        int temp[size + 1];
        int j = size;
        for (int i = 0; i < j; ++i)
        {
            cout << extractMin() << " ";
            // cout << temp[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Heap size ?? " << endl;
    cin >> n;
    // heap *root = new heap;
    heap root(n);

    cout << "Enter " << n << " Elements" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root.insert(x);
    }
    while (1)
    {
        cout << endl
             << "1:Insert 2:Find 3:Print 4:Sort 5:Delete 6:Extract Head 7: E" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter Element to be inserted" << endl;
            cin >> n;
            root.insert(n);
            break;
        case 2:
            cout << "Enter Element to find" << endl;
            cin >> n;
            if (root.find(n))
                cout << "Found" << endl;
            else
                cout << "Not Found " << endl;
            break;
        case 3:
        {
            root.print();
            // temp.print();
            break;
        }
        case 4:
        {
            heap temp = root;
            temp.HeapSort();
            break;
        }
        case 5:
            cout << "Element to be deleted ?" << endl;
            cin >> n;
            root.deletekey(n);
            break;
        case 6:{
            int x = root.extractMin();
            if (x == INT_MAX)
            {
                cout << "Empty Heap";
            }
            else
                cout << x;
            break;
        }
        case 7:
            return 0;
        default:
            cout << "NOT A VALID CHOISE" << endl;
        }
    }
    p@ssword@teamviewer
}