#include<bits/stdc++.h>
using namespace std;

// Here it is implemented using map we can also use matrix to create a graph

class Graph{
    public:
        map<int, list<int>> adj;

        void addEdge(int u,int v,bool direction){
            // Direction = 0  -> Undirected Graph
            // Direction = 1  -> Directed Graph

            // Create an Edge from u to v
            adj[u].push_back(v);
            if(direction == 0){
                // Agar non directed graph hai toh jaise u se v ka connection bana
                // Waise hi v to u ka bhi connection banega
                adj[v].push_back(u);
            }

        }

        void printAdjList(){
            for(auto &i : adj){
                cout<<i.first<<"-> ";
                for(auto &j : i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }
};

int main(){

    int n,m;
    cout<<"Enter number of Nodes and Edges: ";
    cin>>n>>m;

    Graph g; 

    cout<<"Enter Connection of each Node to the next Node: "<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // Creating an Undirected Graph
        g.addEdge(u,v,0);
    }

    // Print Graph
    g.printAdjList();
}