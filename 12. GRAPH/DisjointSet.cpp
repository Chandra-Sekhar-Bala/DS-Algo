#include<iostream>
#include<vector>
using namespace std;
#define N 100
vector <int> parent(N,-1);
vector<int> Rank(N,0);
static int ct = 0;// To check the path compression:
int findParent(int node){
    ct++;
    if(node == parent[node])
        return node;

    // return findParent(parent[node]);
    return parent[node] = findParent(parent[node]);
}

void Union(int u, int v){

    if(Rank[u] > Rank[v])
        parent[v] = u;
    else if(Rank[u] < Rank[v])
        parent[u] =  v;
    else{
        parent[v] = u;
        Rank[u]++;
    }
}

int main(){
    for(int i=0;i < N; i++)
        parent[i] =i;

    Union(1,2);
    Union(2,3);
    Union(4,5);
    Union(5,6);
    Union(6,7);

    cout << "parent of 3 : " <<" Cost :"<< ct << " " << findParent(3) <<  endl ; 
    ct =0;
    cout << "parent of 5 : "<<" Cost :"<< ct << " " << findParent(5) <<  endl ;
    ct =0;
    cout << "parent of 7 : "<<" Cost :"<< ct << " " << findParent(7) <<  endl ; 
    ct =0;
    Union(3,7);
    cout << "parent of 3 : "<<" Cost :"<< ct << " " << findParent(3) <<  endl ;
    ct =0;
    cout << "parent of 5 : "<<" Cost :"<< ct << " " << findParent(5) <<  endl ;
    return 0;
}

/*
*Without path compression -->>

parent of 3 :  Cost :3 1
parent of 5 :  Cost :2 4
parent of 7 :  Cost :4 4
parent of 3 :  Cost :3 1
parent of 5 :  Cost :2 4
*/

/* 
*Using path compression: -->>

parent of 3 :  Cost :3 1
parent of 5 :  Cost :2 4
parent of 7 :  Cost :4 4
parent of 3 :  Cost :2 1
parent of 5 :  Cost :2 4
*/