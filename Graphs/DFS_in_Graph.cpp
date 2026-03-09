#include<bits/stdc++.h>
using namespace std;

void dfsRec(int node, vector<vector<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans){

    visited[node] = true;  // curr node ko visited mark kardo
    ans.push_back(node);  // and curr node ko ans mein push kardo

    for(int i=0;i<adj[node].size();i++){
        // Curr Node ka neighbour nikalo
        int neighbour = adj[node][i];

        // Agar neighbour exists then call recursive function but ab curr node ki jagah neighbour ko pass kardo
        if(!visited[neighbour]){
            dfsRec(neighbour,adj,visited,ans);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj, int n){
    
    vector<int> ans;  // Stores the final BFS Order
    unordered_map<int,bool> visited;  // Checks for visited nodes

    for(int i=0;i<n;i++){   // This loop is to handle disconnected graph
        if(!visited[i]){
            dfsRec(i,adj,visited,ans);  // Recursive Call
        }
    }

    return ans;
}

int main(){
    
    int n = 6;
    
    vector<vector<int>> adj(n);
    
    adj[0] = {4};
    adj[1] = {4,5};
    adj[2] = {3,4};
    adj[3] = {2,5};
    adj[4] = {0,1,2};
    adj[5] = {1,3};
    
    vector<int> result = dfs(adj,n);
    
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}