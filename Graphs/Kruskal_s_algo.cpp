#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];   // sort on the basis of weight which is stored in 2nd index of edges
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){

    for(int i=0;i<n;i++){
        parent[i] = i;   // Initially har node ka parent woh khud hai
        rank[i] = 0;   // Sabka rank 0 hai initially
    }
}

int findParent(vector<int> &parent, int node){  // O(1)
    if(parent[node] == node){  // Final parent tak pohach chuke ho
        return node;
    }

    // Recursive call to find parent and this also has path compression
    return parent[node] = findParent(parent,parent[node]);  // find parent se node ka parent pata krke parent wale vector mein daldo
}

void unionSet(int u, int v, vector<int> &rank, vector<int> &parent){    // O(1)
    u = findParent(parent,u);  // u ka parent nikalo
    v = findParent(parent,v);

    if(rank[u] < rank[v]){  // Agar u ke parent ka rank v ke parent ke rank se kam hai toh u ka parent v ke parent se judh jayega
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){  // Agar v ke parent ka rank u ke parent ke rank se kam hai toh v ka parent u ke parent se judh jayega
        parent[v] = u;
    }
    else{  // same rank;
        parent[v] = u;
        rank[u]++;
    }
}

int spanningTree(vector<vector<int>> &edges, int n){

    sort(edges.begin(),edges.end(),cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);

    int minWeight = 0;  // Store Total weight of MST

    for(int i=0;i<edges.size();i++){
        int u = findParent(parent,edges[i][0]);  // since u lies in [i][0] index in edges find parent of u
        int v = findParent(parent,edges[i][1]);  
        int w = edges[i][2];

        if(u != v){
            minWeight += w;
            unionSet(u,v,rank,parent);  // Agar u and v ke parent alag hai matlab both belong to different components in a graph so join them
        }
    }
    return minWeight;
}

int main(){
    int n = 7;
    
    vector<vector<int>> edges = {{1,2,2},{1,4,1},{1,5,4},{4,5,9},{4,3,5},{2,4,3},{2,3,3},{2,6,7},{3,6,8}};

    int ans = spanningTree(edges,n);
    cout<<"Weight of MST is: "<<ans<<endl;
}