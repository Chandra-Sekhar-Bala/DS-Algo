#include <iostream>
using namespace std;
#define INF 999
class garaph
{
    int v, e;
    int *adj;

public:
    garaph() {}

    garaph(int v, int arr[])
    {
        this->v = v;
        adj = new int[v * v];

        for (int i = 0; i < v * v; i++)
        {

            *(adj + i) = arr[i];
        }
    }

    void floyedWarshall()
    {
        int diff[v][v];

        // copy cat
        for (int i = 0; i < v; i++)
        {

            for (int j = 0; j < v; j++)
            {
                diff[i][j] = *(adj +i * v + j);
            }
        }

        // main algo part
        for (int k = 0; k < v; k++)
        {
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    if (diff[i][k] + diff[k][j] < diff[i][j])
                    {
                        *(adj + i * v + j) = diff[i][k] + diff[k][j];
                    }
                }
            }
        }
    }

    void printGraph()
    {

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {

                if (*(adj + i * v + j) == INF)
                {
                    std::cout << "INF"
                              << "  ";
                    continue;
                }
                std::cout << *(adj + i * v + j) << "  ";
            }
            std::cout << std::endl;
        }
    }
};
int main()
{

    int arr[] = {0, 5, INF, 10,
                 INF, 0, 3, INF,
                 INF, INF, 0, 1,
                 INF, INF, INF, 0};

    garaph G(4, arr);
    std::cout << "Original Graph: " << std::endl;
    G.printGraph();
    std::cout << "Updated  Graph: " << std::endl<< endl;
    G.floyedWarshall();
    G.printGraph();

    return 0;
}