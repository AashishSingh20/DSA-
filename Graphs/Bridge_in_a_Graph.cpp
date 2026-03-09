#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, vector<bool> &vis, vector<vector<int>> &adj){
    
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for(auto neighbour : adj[node]){
        if(neighbour == parent){  // Agar neighbour hi parent hai then ignore
            continue;
        }
        if(!vis[neighbour]){  // agar neighbour visited nahi hai call dfs
            dfs(neighbour,node,timer,disc,low,result,vis,adj);
            low[node] = min(low[node],low[neighbour]);

            // check edge is bridge
            if(low[neighbour] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else{
            // BackEdge
            // Node already visited and no parent
            low[node] = min(low[node],disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int n){
    
    // Creating adjacency list
    vector<vector<int>> adj(n);
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
    
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;

    vector<int> disc(n,-1);
    vector<int> low(n,-1);

    int parent = -1;
    vector<bool> vis(n,false);
    vector<vector<int>> result;

    // Dfs
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,vis,adj);
        }
    }
    return result;
}

int main(){
    int n = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,2},{3,4}};

    vector<vector<int>> ans = findBridges(edges,n);

    cout<<"Bridges in the Graph are: "<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}