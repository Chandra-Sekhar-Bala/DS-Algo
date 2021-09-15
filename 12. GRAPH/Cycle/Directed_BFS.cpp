#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<vector>
#include<stack>
// Directed BFs
using namespace std;
class Graph{
    int v;
    map<int,list<int>> G;
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

    bool CycleDetection(){
        vector<int> indeg(v+1,0);
        stack<int> st;

        for(auto x: G)
            for(auto i: G[x.first])
                indeg[i]++; // Checkig How many Edges are connected with i'th node

        
        for(auto i: G)
            if(indeg[i.first]==0)
                st.push(i.first); // pushing the non-Cyclic Nodes as None of edge are conneced with them
        
        int ct =-1;

        while(!st.empty()){
            int src = st.top();
            st.pop(); ct++;
            for(auto i: G[src]){
                indeg[i]--; // src node is processed and no egde is conncting i'th adjacent node and src node

                if(indeg[i]==0)
                    st.push(i);
            }

        }
  
        if(ct==v)
            cout << "NO Cycle Present as it's a DAG " <<ct << " "<< v <<endl; 
        else
            cout << "Cycle Present as it's not a DAG " <<ct << " "<< v <<endl;
    }

    
};

int main(){
    // Graph g(3);
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(4,1);
    g.addEdge(1,2);
    // g.addEdge(2,3);
    g.addEdge(1,3);
    g.print();
    g.CycleDetection() ;  

}


/*
        0
      /  
     1
     \
     2 
     \
     3


*/