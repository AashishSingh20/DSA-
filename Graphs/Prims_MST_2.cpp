#include<bits/stdc++.h>
using namespace std;

int spanningTree(vector<vector<pair<int,int>>> &adj, int n){

    vector<int> key(n,INT_MAX);
    vector<bool> mst(n,false);

// Find min weight using min heap {weight,node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,0});  // {weight, startNode}
    int sum = 0;   // Final final sum of weights of all MST edges

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int wt = it.first;   // Gets the weight of the curr node
        int node = it.second;  // gets the value in currNode

        if(mst[node]){  // Agar node mst mein true mark hai then ignore it
            continue;
        }

        mst[node] = true;  // Agar node false marked tha mst mein toh mark it true
        sum += wt;  // sum mein weight daldo curr node tak ka

        for(auto neighbour : adj[node]){
            int adjNode = neighbour.first;  // adjNode stores value at neighbour node
            int adjWt = neighbour.second;  // adjWt stores weight till the neighbour node

            if(!mst[adjNode]){   // Agar adjNode false marked hai to usko priority queue mein push kardo
                pq.push({adjWt,adjNode});
            }
        }
    }
    return sum;
}

int main(){
    int n = 5;
    
    vector<vector<pair<int,int>>> adj(n);  // {node,weight}
    
    // Undirected Graph with weights
    adj[0] = {{1,2},{3,6}};
    adj[1] = {{0,2},{2,3},{3,8},{4,5}};
    adj[2] = {{1,3},{4,7}};
    adj[3] = {{0,6},{1,8}};
    adj[4] = {{1,5},{2,7}};

    int ans = spanningTree(adj,n);
    cout<<"Weight of MST is: "<<ans<<endl;

}