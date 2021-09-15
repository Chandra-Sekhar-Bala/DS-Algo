#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v ;
    map<int,list<int>> G;
    public:
    Graph(int v){
        this->v = v;
    }
    void addEgde(int src,int des){
        G[src].push_back(des);
        G[des].push_back(src);
    }

    void print(){
        for(auto i: G){ // getting first pair
        cout <<i.first << "->";
        for(auto j: G[i.first]){ // list values of index 'i.first'
            cout << j << "->";
        }
        cout << endl;
        }
    }

    bool BFSCycle(int src){

        vector<int>visited(v,0);
        queue<int> q;
        
        q.push(src);
        visited[src] = 1;

        while(!q.empty()){
            src = q.front();
            q.pop();
            visited[src] = 2;        
            for(auto x: G[src]){

                if(visited[x]==1){
                return true;
                }

                if(x!=2){
                q.push(x);
                visited[x]=1;
                }
            }
        }
        return false;
    }

};

int main(){

    Graph g(4);
    g.addEgde(1,2);
    g.addEgde(2,3);
    g.addEgde(3,4);
    g.addEgde(4,1);
    g.print();
    
    if(g.BFSCycle(1))
    cout << "Graph Contin a cycle"<<endl;
    else
    cout << "Graph does NOT  contain a Cycle"<<endl;

    return 0;
}