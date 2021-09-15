#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
// Only works in DAG(Directed Acyclic Graph)-->
using namespace std;
class Graph{
    int v;
    unordered_map<int,list<int>> G;
    public:
    Graph(int v){
        this->v = v;
    }
    
    void addEdge(int src, int des){
        G[src].push_back(des); // Directed Graph
    }

    void print(){
        for(auto i: G){
            cout << i.first << "->";
            for(auto j: G[i.first]){
                cout << j << "->";
            }
            cout << endl;
        }
    }

    void Kahans(){
        vector< int > indeg(v+1,0);

        // intiilizing Indegree Array:
        for(auto i: G){
            for(auto j: G[i.first])
                indeg[j]++;
        }
        stack<int> st;

        for(auto x: G){
            if(indeg[x.first]==0)
                st.push(x.first);

        }

        cout << "According to Kahan'a algo, Toposrt is: "<< endl;

        while(!st.empty()){
           int  src = st.top(); 
           st.pop();
           cout << src << "->";

            for(auto x: G[src]){
               indeg[x]--;

               if(indeg[x]==0)
                st.push(x);
            }
        }


    }
};

int main(){
    Graph g(6);;
    g.addEdge(5,0);
    g.addEdge(0,5);
    g.addEdge(4,0);
    g.addEdge(5,2);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.print();
    g.Kahans();
}

// OK-Checked;