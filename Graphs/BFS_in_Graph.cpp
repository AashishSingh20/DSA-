#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int n){
    
    vector<int> ans;  // Stores the final BFS Order
    unordered_map<int,bool> visited;  // Checks for visited nodes
    queue<int> q;

    for(int i=0;i<n;i++){  // Handles case of disconnected graph
        // Agar first node is not visited then push it in queue and mark it as visited
        if(!visited[i]){
            q.push(i);
            visited[i] = true;

            while(!q.empty()){
                int frontNode = q.front();  // frontNode mein queue ke front ka element daldo
                q.pop();  // ab queue ko pop kardo
        
                ans.push_back(frontNode);  // ans mein frontNode ki value store karlo
        
                for(int j=0;j<adj[frontNode].size();j++){  // Traverse the list of the root node(currently it is 0(check it's neighbours))
                    int neighbour = adj[frontNode][j]; 
        
                    if(!visited[neighbour]){    // Agar neighbour is not visited 
                        q.push(neighbour);  // put it in queue
                        visited[neighbour] = true;  //and mark it as visited 
                    }
                }
            }
        }
    }

    return ans;   // Return final ans;
}

int main(){
    
    int n = 5;
    
    vector<vector<int>> adj(n);
    
    adj[0] = {3};
    adj[1] = {2,3,4};
    adj[2] = {1};
    adj[3] = {0,1};
    adj[4] = {1};
    
    vector<int> result = bfs(adj,n);
    
    for(int x : result)  // Result ki values ko x mein dalo and print x until result is completed
        cout<<x<<" ";
}
