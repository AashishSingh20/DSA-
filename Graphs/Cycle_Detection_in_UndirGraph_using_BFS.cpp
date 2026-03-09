#include<bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int src, vector<vector<int>> &adj, unordered_map<int,bool> &visited){
    unordered_map<int,int> parent;  // Marks parent of the curr node
    
    // Initial element ka parent -1 hi hoga
    parent[src] = -1;
    visited[src] = true;
    
    queue<int> q;
    q.push(src);  // Queue mein first node daldo 
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto neighbour: adj[front]){  
            // If curr node's element is already visited 
            // and it's neighbour is not it's parent then it is a cyclic graph
            if(visited[neighbour] && neighbour != parent[front]){
                return true;
            }
            // If curr node(front) ka neighbout is not visited then 
            else if(!visited[neighbour]){
                q.push(neighbour);   // Push neighbour in queue
                visited[neighbour] = true;   // mark neighbour as visited
                parent[neighbour] = front;  // mark front as the parent of neighbour
            }
        }
    }     
    return false;
}

bool isCycle(vector<vector<int>> &adj, int n){

    unordered_map<int,bool> visited;  // Checks for visited nodes

    for(int i=0;i<n;i++){  // Handles case of disconnected graph
        // Agar first node is not visited then push it in queue and mark it as visited
        if(!visited[i]){
            if(isCyclicBFS(i,adj,visited)){
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
