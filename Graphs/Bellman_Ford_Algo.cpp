#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<int>> &edges, int src, int n){

    vector<int> dist(n+1,INT_MAX);
    dist[src] = 0;

    // (n-1 times)
    for(int i=1;i<=n-1;i++){
        // Traverse on all edges
        for(int j=0;j<edges.size();j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];   

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check for negative cycle
    // Traverse on all edges
    for(int j=0;j<edges.size();j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];  

        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
            cout<<"Negative CYcle Detected !";
            return {};
        }
    }

    vector<int> ans;
    for(int i=0;i<dist.size();i++){
        if(dist[i] != INT_MAX){
            ans.push_back(dist[i]);
        }
    }
    return ans;
}

int main(){
    int n = 3;
    
    vector<vector<int>> edges = {{1,2,2},{1,3,2},{2,3,-1}};

    int src;
    cout<<"Enter Source Node: ";
    cin>>src;

    vector<int> ans = bellmanFord(edges,src,n);
    cout<<"Shortest Distances from source to all nodes are: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}