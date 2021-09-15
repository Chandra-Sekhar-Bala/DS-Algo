#include<iostream>
#include<list>
using namespace std;
class graph{
    int v,e;
    list<int> *L;
    public:
    graph(){}
    graph(int v,int e){
        this->v = v;
        this->e = e;
        L= new list<int> [v];
    }
    void addEdge(int x , int y){
        // non - direceted graph lol
        L[x].push_back(y);
        L[y].push_back(x);
    }
    void print(){
        for(int i=0; i<v; i++){
            cout << i ;
            for(auto x: L[i])
            cout <<"->"<< x ;
        cout << endl;
        }
    }
};

int main(){
    graph *g = new graph(4,5);
    g->addEdge(0,1);
    g->addEdge(0,2);
    g->addEdge(1,2);
    g->addEdge(2,3);
    g->addEdge(3,0);
    g->print();


}