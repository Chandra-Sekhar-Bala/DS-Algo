#include<iostream>
using namespace std;
class ListNode{
    public:
    int vertex;
    ListNode* next;
    ListNode(){vertex = 0; next = NULL;}
};
class Graph{

    
    int v;
    int e;
    ListNode* adj;

    public:
    Graph(){
        v=e=0;
        adj= NULL;
    }

    void createGraph(){
    cout << "Enter Vertex and Egde number"<<endl;
    cin >> v >> e;
    adj = new ListNode[v];
    
    for(int i=0; i<v; i++){
        adj[i].vertex = i;
        adj[i].next =NULL;
    }
    printGraph();

    int x,y;
    cout <<"Enter Source & Destination Connecting Lines in pair: "<<endl;

    for(int i=0; i<e; i++){
        cin >> x >> y;

        ListNode * temp = new ListNode;
        temp->vertex = y;

        ListNode* t = adj+x;

        while(t->next!=NULL)
        t= t ->next;

        t->next = temp;

     }
    }

    void printGraph(){
        cout << endl;
        for(int i=0; i<v;i++){
        ListNode* temp = adj+i;
        while(temp){
            cout << temp->vertex << "->";
            temp = temp->next;
        }
        cout << endl;
        }
        cout << endl;
    }
};
int main(){
Graph G ;
 G.createGraph();
G.printGraph();
}