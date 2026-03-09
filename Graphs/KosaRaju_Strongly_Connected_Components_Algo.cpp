#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj){

    vis[node] = true;

    for(auto neighbour : adj[node]){
        if(!vis[neighbour]){
            dfs(neighbour,vis,st,adj);
        }
    }

    // topo logic
    st.push(node);
}

void revDfs(int node, vector<bool> &vis, vector<vector<int>> &transpose){
    vis[node] = true;  // curr node joh top par tha usse visited mark kardo

    for(auto neighbour : transpose[node]){  // curr node ka neighbour nikalo 
        if(!vis[neighbour]){    // If neighbour is not visited then recursive call
            revDfs(neighbour,vis,transpose);
        }
    }
}

int kosaraju(vector<vector<int>> &adj, int n){

    // Topo Sort
    stack<int> st;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }

    // Create a transpose graph
    vector<vector<int>> transpose(n);
    for(int i=0;i<n;i++){
        vis[i] = 0;  // visted of i ko pehle false kardo then process further
        for(auto neighbour : adj[i]){
            transpose[neighbour].push_back(i);   // Direction change ho jayega saare edges ka
        }
    }

    // Dfs calling using aboe ordering
    int count = 0;  // Counts the number of strongly connected nodes
    while(!st.empty()){    // Stack empty hai tabtak loop chalao
        int top = st.top();  // top mein stack ka top element daldo
        st.pop();  

        if(!vis[top]){   // Agar top element is not visited then
            count++;   // count ko badhado 
            revDfs(top,vis,transpose);  // Ab phir sabpar dfs karo
        }
    }
    return count;   // return the number of SCC
}

int main(){

    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0};
    adj[3] = {4};
    adj[4] = {};

    int ans = kosaraju(adj,n);
    cout<<"Strongly Connected Components are: "<<ans<<endl;
}