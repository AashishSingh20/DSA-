#include<bits/stdc++.h>
using namespace std;

// Solved using Kahn's Algo(BFS)
bool isCycle(vector<vector<int>> &adj, int n){

    vector<int> indegree(n);
    for(auto &i: adj){
        for(auto &j : i){
            indegree[j]++;
        }
    }

    // 0 indegree walo ko push kardo
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // Do BFS
    int count = 0;
    while(!q.empty()){
        // front mein q ka front element daalo
        int front = q.front();
        q.pop();  //Aur q ko pop kardo

        count++;

        // Neighbour ke Degree Update kardo
        for(auto neighbour : adj[front]){  // Front ke neighbours mein check karo
            indegree[neighbour]--;  // Aur uske neighbour ke indegree ko decrement kardo

            if(indegree[neighbour] == 0){  // Agar kisi neighbour ka indegree 0 ho jaye toh push in queue
                q.push(neighbour);
            }
        }
    }

    // If all nodes processed → No cycle
    if(count == n)
        return false;
    else
        return true;
}

int main(){

    int n = 7;
    
    vector<vector<int>> adj(n);
    
    // Directed Graph
    adj[0] = {};
    adj[1] = {2,3};
    adj[2] = {4};
    adj[3] = {4};
    adj[4] = {5,6};
    adj[5] = {6};
    adj[6] = {};  

    if(isCycle(adj,n)){
        cout<<"Graph is Cyclic";
    }
    else{
        cout<<"Graph is Acyclic";
    }
}