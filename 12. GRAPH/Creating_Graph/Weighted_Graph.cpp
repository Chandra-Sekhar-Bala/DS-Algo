#include<iostream>
#include<list>
#include<unordered_map>
#include<map>
using namespace std;
class Graph{

    map<string,list<pair<string,int>>> G;
    public:
    void addEdge(string src, string des,int weight ,bool isdir){
        // list<string,int> temp;

        G[src].push_back(make_pair(des,weight));
        if(isdir){
        G[des].push_back(make_pair(src,weight));
        }
    }
    void print(){
        for(auto i:G){
            cout << "To City: "<<i.first<<"->  ";
            for(auto x: i.second){
            cout << x.first<<" "<<x.second<<"km,";
            }
            cout << endl;
        }
    }

};
int main(){
    Graph g;
    g.addEdge("A","B",10,false);
    g.addEdge("A","C",50,true);
    g.addEdge("B","C",9,true);
    g.addEdge("C","D",4,false);
    g.addEdge("D","E",12,true);
    g.addEdge("F","H",15,true);
    g.print();

}
