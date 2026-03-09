#include<bits/stdc++.h>
using namespace std;

void getShortestPath(int src, vector<vector<pair<int,int>>> &adj, vector<int> &dist, stack<int> &st){
    dist[src] = 0;  // src node ka distance from src will always be 0 until self loop

    while(!st.empty()){  // dfs mein hamne stack bhar diya ab run this loop until empty
        int top = st.top();  // top mein stack ka top element daalo
        st.pop();  // stack ko pop kardo

        if(dist[top] != INT_MAX){  // Agar dist mein top wale element ki value INT_MAX nahi hai then  
            for(auto i: adj[top]){    // top jis list mein tha uske 
                if(dist[top] + i.second < dist[i.first]){   // dist mein top wale index ko add karo with distance in i if it is smaller then the previous distance stored in dist
                    dist[i.first] = dist[top] + i.second;  // Update dist
                }
            }
        }
    }
}

void dfs(int node, vector<vector<pair<int,int>>> &adj, vector<bool> &visited, stack<int> &st){

    visited[node] = true;  // Curr node ko visited mark kardo

    for(auto neighbour : adj[node]){   // har node ka neighbour check karo
        if(!visited[neighbour.first]){  // Agar node ka neighbour visited nahi hai toh call dfs
            dfs(neighbour.first,adj,visited,st);
        }
    }
    st.push(node);  // Put node in stack during return call
}

vector<int> shortestPath(vector<vector<pair<int,int>>> &adj, int n){

    vector<bool> visited(n,false);  // Initialize visited array with false values and size n
    stack<int> st;  // Create stack to get Topological Sort
    // Topological Sort
    for(int i=0;i<n;i++){
        if(!visited[i]){  // Agar element is not marked visited call dfs function
            dfs(i,adj,visited,st);
        }
    }

    int src = 1;  // We have to find shortest distance from node 1 to all nodes
    vector<int> dist(n,INT_MAX);  // n size ka dist array banao aur saari values ko INT_MAX se initialize kardo
    
    getShortestPath(src,adj,dist,st);  // Ab Call function to get shortest
    
    for(int i=0;i<n;i++){  // Traverse the whole dist array 
        if(dist[i] == INT_MAX){   // Agar kahi bhi INT_MAX mile toh usse usmein -1 daldo
            dist[i] = -1;
        }  
    }

    return dist;  // Return Shortest Distances of 1 from all nodes
}

int main(){
    
    int n = 6;
    
    vector<vector<pair<int,int>>> adj(n);
    
    // Directed Graph with weights
    adj[0] = {{1,5},{2,3}};
    adj[1] = {{2,2},{3,6}};
    adj[2] = {{3,7},{4,4},{5,2}};
    adj[3] = {{4,-1}};
    adj[4] = {{5,-2}};
    adj[5] = {};

    vector<int> ans = shortestPath(adj,n);
    cout<<"Shortest path from source node to all nodes is: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}