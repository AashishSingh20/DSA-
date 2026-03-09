#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &ap){

    vis[node] = true;
    disc[node] = low[node] = timer++;
    
    int child = 0;

    for(auto neighbour : adj[node]){
        if(neighbour == parent){
            continue;
        }
        
        if(!vis[neighbour]){
            dfs(neighbour,node,timer,disc,low,vis,adj,ap);
            low[node] = min(low[node],low[neighbour]);  // return aate time node ke low ko update kardo

            // Check articulation point or not
            if(low[neighbour] >= disc[node] && parent != -1){  // Agar neihbour node ke pehle wale node se nahi juda hai and agar uska parent -1 nahi hai then it is AP
                ap[node] = 1;
            }
            child++;  // node ka child exists karta hai increase it's child count
        }
        else{
            low[node] = min(low[node],disc[neighbour]);
        }
    }

    if(parent == -1 && child > 1){  // Agar kisi ka parent -1 hai and uske 1 se jada child hai to it is an AP(source node hai)
        ap[node] = 1;
    }
}

vector<int> articulationPoints(vector<vector<int>> &adj, int n){

    int timer = 0;

    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    vector<bool> vis(n,false);

    vector<int> ap(n,0);  // Stores the Final Articulation points

    int parent = -1;

    // dfs
    for(int i=0;i<n;i++){
        if(!vis[i]){  // If i is not visited
            dfs(i,parent,timer,disc,low,vis,adj,ap);
        }
    }

    return ap;
}

int main(){
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1,3,4};
    adj[1] = {0,2};
    adj[2] = {1};
    adj[3] = {0,4};
    adj[4] = {0,3};

    // Printing Articulation Points
    vector<int> ans = articulationPoints(adj,n);
    cout<<"Articulation points in the given graph are as follows: ";
    for(int i=0;i<ans.size();i++){
        if(ans[i] != 0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}