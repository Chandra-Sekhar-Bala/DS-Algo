#include<iostream>
#include<map>
#include<list>
#include<vector>
using namespace std;
// cycle detection in Directed Graph using DFS
class Graph{
    int v;
    map<int,list<int>> G;
    public:
    Graph(int v){
        this->v = v;
    }
    void addEdge(int src, int des){
        G[src].push_back(des);
    }

    void Print(){
        for(auto i: G){
            cout << i.first << " ->";
            for(auto x: i.second){
                cout << x << "->";
            }
            cout << endl;
        }
    }
    bool find_Cycle(int src,vector<bool>&visited){
       visited[src] = true;

       for(auto nbr: G[src]){

        if(visited[nbr]){
            return true;
        }
        else{  // if neighbour is not visited then visit & check for cycle
            bool cycle = find_Cycle(nbr,visited);
            return cycle;
        }

       }
       return false;
    }

    bool cycle_Detection(int src){
        vector<bool> visited(v,false); //  need Less memory than map+ No loop for intilization
        return find_Cycle(src,visited);
    }

};

int main(){
     Graph G(4);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(3,4);
    // G.addEdge(4,1);
    G.Print();
    if(G.cycle_Detection(1))
    cout << "There is a Cycle - in Graph"<<endl;
    else
    cout << "There is NO Cycle in Graph"<<endl;
}

/* 
DIRECTED Graph
1-> 2
2-> 3
3-> 4
4-> 1
*/