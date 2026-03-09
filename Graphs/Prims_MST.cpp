#include<bits/stdc++.h>
using namespace std;

int spanningTree(vector<vector<pair<int,int>>> &adj, int n){

    vector<int> key(n,INT_MAX);
    vector<bool> mst(n,false);
    vector<int> parent(n,-1);

    // Start
    key[0] = 0;  // src node ka key 0 hai
    parent[0] = -1;  // 1 is the src node it has no parents so -1
    
    for(int i=0;i<n;i++){

        int mini = INT_MAX;
        int u;

        // find min weight
        for(int v=0;v<n;v++){ 
            if(mst[v] == false && key[v] < mini){  // Agar mst ka vth index false hai and agar us index ka key value mini se chhota hai toh 
                u = v;  // u mein v ko daldo
                mini = key[v];  // mini mein vth index ke key wale element ko daldo as key array mein wohi sabse chhota hai
            }
        }

        // Mark min node as True in mst array;
        mst[u] = true;

        // Check it's adjacent nodes
        // neighbour = {node,weight}
        for(auto neighbour: adj[u]){
            int v = neighbour.first;  // v points to neighbour node
            int w = neighbour.second;  // w is the weight required to reach neighbour

            if(mst[v] == false && w < key[v]){  // Agar mst mein vth index mein false hoga and weight is smaller than weight stored in key at vth index then
                parent[v] = u;  // u ko v ka parent mark kardo
                key[v] = w;  // vth element ke weight ko update kardo with new weight(w)
            }
        }
    }

    int result = 0;
    
    for(int i=0;i<n;i++){
        result += key[i];  
    }
    
    return result;
}

int main(){
    int n = 5;
    
    vector<vector<pair<int,int>>> adj(n);
    
    // Undirected Graph with weights
    adj[0] = {{1,2},{3,6}};
    adj[1] = {{0,2},{2,3},{3,8},{4,5}};
    adj[2] = {{1,3},{4,7}};
    adj[3] = {{0,6},{1,8}};
    adj[4] = {{1,5},{2,7}};

    int ans = spanningTree(adj,n);
    cout<<"Weight of MST is: "<<ans<<endl;

}