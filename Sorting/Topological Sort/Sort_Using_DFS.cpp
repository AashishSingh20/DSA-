#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){

    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour,adj,visited,st);
        }
    }

    // During Return Call Stack mein node ko put kardo then return ( ** IMP)
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &adj, int n){

    vector<bool> visited(n,false);
    stack<int> st;
    // Call DFS Topological Sort
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topoSort(i,adj,visited,st);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main(){

    int n = 7;
    
    vector<vector<int>> adj(n);
    
    // Directed Graph
    adj[0] = {};
    adj[1] = {2,3};
    adj[2] = {4};
    adj[3] = {4};
    adj[4] = {5,6};
    adj[5] = {6};
    adj[6] = {};  
    
    vector<int> ans = topologicalSort(adj,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}