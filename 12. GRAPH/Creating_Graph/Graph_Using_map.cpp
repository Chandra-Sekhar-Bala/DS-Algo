#include<iostream>
#include<list>
#include<map>
using namespace std;
class Graph{
    map<int,list<int>>G;
    public:

    void AddEdge(int src,int des){
        G[src].push_back(des);

    }

    void print(){
        
        for(auto it = G.begin(); it!= G.end(); ++it){
            cout << it->first << "->";
            for(auto x:it->second)
            cout << x << "->";
            cout << endl;
        }
    }

};
using namespace std;
int main(){
    Graph g;
    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(3,0);
    g.print();
}