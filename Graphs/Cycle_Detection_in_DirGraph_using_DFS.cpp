#include<bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int node, vector<vector<int>> &adj, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited){

    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            if(isCyclicDFS(neighbour,adj,visited,dfsVisited)){
                return true;
            }
        }
        // Agar visited treu hai and dfsVisited of that neighbout is also true then cycle is present
        else if(dfsVisited[neighbour]){
            return true;
        }
    }

    // Call se Return aate time dfsVisited wale ko unmark kardo
    dfsVisited[node] = false;
    return false;
}

bool isCycle(vector<vector<int>> &adj, int n){

    unordered_map<int,bool> visited;  // Checks for visited nodes
    unordered_map<int,bool> dfsVisited; // Used in directed Graph
    for(int i=0;i<n;i++){  // Handles case of disconnected graph
        // Agar first node is not visited then push it in queue and mark it as visited
        if(!visited[i]){
            if(isCyclicDFS(i,adj,visited,dfsVisited)){
                return true;  // Cycle Found
            }
        }
    }
    return false;   // Else return false;
}

int main(){
    
    int n = 9;
    
    vector<vector<int>> adj(n);
    
    // Directed Graph
    adj[0] = {};
    adj[1] = {2};
    adj[2] = {3,4};
    adj[3] = {7,8};
    adj[4] = {5};
    adj[5] = {6};
    adj[6] = {4};
    adj[7] = {};
    adj[8] = {7};   
    
    if(isCycle(adj,n)){
        cout<<"Graph is Cyclic";
    }
    else{
        cout<<"Graph is Acyclic";
    }
}
