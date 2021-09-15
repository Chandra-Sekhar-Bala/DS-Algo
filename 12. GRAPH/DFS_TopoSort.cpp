#include<iostream>
#include<list>
#include<map>
#include<vector>
#include <stack>
#include<unordered_map>
// Is it a DAG(Directed Acyclic Graph):-->
using namespace std;
class Graph{
    int v;
    unordered_map<int,list<int>> G;
    public:
    Graph(int v){
        this->v = v;
    }

    void addEdge(int src, int des){
        G[src].push_back(des);
    }

    void print(){
        for(auto pair: G){
            cout << pair.first << "->";
            for(auto it: G[pair.first])
                cout << it << "->";
            cout <<  endl;
        }
    }

    void find_topo(int src, vector<int> &visited, stack<int> &st){
        visited[src]= 1;
        for(auto it: G[src]){
        cout << "it: "<< it << "->";
            if(visited[it] == 0)
            find_topo(it,visited,st);
        }
        st.push(src);
    }

    vector <int> TopoSort(){
        vector<int > visited(v+1,0);
        stack<int > st;
        for(auto x: G){
            cout << "Visited "<< x.first << endl;
            if(visited[x.first] == 0)
            find_topo(x.first,visited,st);
        }
        vector<int> ans;
        for(int i=0; i< v; i++){
            cout << st.top() << "->";
            ans.push_back(st.top());
            st.pop();            
        }
        return ans;
    }
};

int main(){
    Graph G(5);
    G.addEdge(5,0);
    G.addEdge(5,2);
    G.addEdge(4,0);
    G.addEdge(4,1);
    G.addEdge(2,3);
    G.addEdge(3,1);
    G.addEdge(1,6);
    G.print();

    vector<int> ans (5);
    ans =  G.TopoSort();
    cout << "DONE" << endl;
    for(auto x: ans){
        cout << x << " ";
    }
}










#include <bits/stdc++.h>

using namespace std;
  int kthSmallest(int arr, int k) {
    //   cout << sizeof(arr) <<endl;
    //   int n =/ sizeof(int);
    //   cout << n << endl;
         
    }

int main()
{
    int arr[] = {7, 10, 4 ,20,15};
    sort(arr+0, arr+5);
    cout << sizeof(arr)<< endl;
         for(auto x :arr)
         cout << x << " ";
        cout <<endl<< arr[4-1];
    
    // cout<< kthSmallest(a,4);

    return 0;
}
