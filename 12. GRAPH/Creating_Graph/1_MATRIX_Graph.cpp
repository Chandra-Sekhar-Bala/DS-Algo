#include <iostream>
using namespace std;
class graph
{
    int v;
    int e;
    int **adj;

public:

     void print()
    {
         cout <<endl<< "The Graph Matrix:"<<endl;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << adj[i][j] <<"  ";
            }
            cout << endl;
        }
    }

    void createGraph()
    {
        cout << "Enter Numbers of Vertices and Edges" << endl;
        cin >> this->v >> e;

        adj = new int *[v];
        // Now adj(double pointer) will point a arrray of pointers of size 'v'
        for (int i = 0; i < v; i++)
            adj[i] = new int[v]; // assigining every arry of pointers a 'v' size int block

        for (int i = 0; i < v; i++){
            for (int j = 0; j < v; j++)
                adj[i][j] = 0;
        }

        cout << "Enter node number with a pair connecing an Edge" << endl;
        int x, y;

        for (int j = 0; j < e; j++)
        {
            cin >> x >> y;
            adj[x][y] = 1;
            adj[y][x] = 1; //-> assuming an undiected grap
        }
    }
    
};
int main()
{
    graph g;
    g.createGraph();
    g.print();

}