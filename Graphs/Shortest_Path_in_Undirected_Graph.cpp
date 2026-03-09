#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &adj, int src,int dest, int n){

    vector<bool> visited(n,false);  // Marks whether the curr node is visited or not
    vector<int> parent(n,-1);  // Track parents of every node initially sabke parents ki jagah -1 daldo

    queue<int> q;
    q.push(src);  // src node ko queue mein push kardo
    visited[src] = true;  // mark true for src in visited

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(!visited[neighbour]){
                visited[neighbour] = true;  // neighbour ko visited mark kardo
                parent[neighbour] = front;  // front ko neighbour ka parent mark kardo
                q.push(neighbour);  // neighbour ko queue mein push kardo
            }
        }
    }

    // Prepare Shortest Path
    vector<int> ans;
    int currNode = dest;  // currNode is pointing to the destination node
    ans.push_back(dest);

    while(currNode != src){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    return ans;
}

int main(){
    
    int n = 9;
    
    vector<vector<int>> adj(n);
    
    // Directed Graph
    adj[0] = {};
    adj[1] = {2,3,4};
    adj[2] = {1,5};
    adj[3] = {1,8};
    adj[4] = {1,6};
    adj[5] = {2,8};
    adj[6] = {4,7};  
    adj[7] = {6,8};  
    adj[8] = {3,5,7};

    int src;
    cout<<"Enter Source Node: ";
    cin>>src;

    int dest;
    cout<<"Enter Destination Node: ";
    cin>>dest;

    vector<int> shortest = shortestPath(adj,src,dest,n);
    cout<<"Shortest Path in the Graph from Source to Destination is: ";
    for(int i=shortest.size()-1;i>=0;i--){
        cout<<shortest[i]<<" ";
    }
    cout<<endl;
}