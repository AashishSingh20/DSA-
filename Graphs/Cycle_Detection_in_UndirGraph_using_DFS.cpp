#include<bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int node, int parent, vector<vector<int>> &adj, unordered_map<int,bool> &visited){
    
    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            // Recursive Call for checking cycle and DFS Traversal
            bool cycleDetected = isCyclicDFS(neighbour,node,adj,visited);
            if(cycleDetected){
                return true;
            }
        }
        else if(neighbour != parent){  // If neighbour is marked visited but neighbour != parent Cycle is present
            // Cycle Present
            return true;
        }
    }
}

bool isCycle(vector<vector<int>> &adj, int n){

    unordered_map<int,bool> visited;  // Checks for visited nodes

    for(int i=0;i<n;i++){  // Handles case of disconnected graph
        // Agar first node is not visited then push it in queue and mark it as visited
        if(!visited[i]){
            if(isCyclicDFS(i,-1,adj,visited)){
                return true;
            }
        }
    }
    return false;   // Else return false;
}

int main(){
    
    int n = 10;
    
    vector<vector<int>> adj(n);
    
    adj[0] = {};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {2};
    adj[4] = {5};
    adj[5] = {4,6,7};
    adj[6] = {5,8};
    adj[7] = {5,8};
    adj[8] = {6,7,9};
    adj[9] = {8};
    
    if(isCycle(adj,n)){
        cout<<"Graph is Cyclic";
    }
    else{
        cout<<"Graph is Acyclic";
    }
}
