#include<bits/stdc++.h>
using namespace std;

// Uses Djikstra's with parent indexing

vector<int> shortestPath(vector<vector<pair<int,int>>> &adj, int src, int n){

    vector<int> dist(n+1,INT_MAX);
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++){   // parent mein from 1st index to last index mein unke index number hi daldo
        parent[i] = i; 
    }
    
    set<pair<int,int>> st; // Using set (<Distance from source Node to curr node,curr Node>)

    dist[src] = 0;  // Source node ka distance hamesha 0 hoga
    st.insert({0,src});  // We using set as it store elements in ascensing order so smallest distance is at top

    while(!st.empty()){
        // Fetch top record
        auto top = *(st.begin());  // Top ke andar set ka top element daldo

        int nodeDistance = top.first;  // top ka 1st mein distance hoga
        int topNode = top.second;   // And top ka second topNode kon hai toh hoga

        // Remove top record
        st.erase(st.begin());

        // Traverse neighbours
        for(auto neighbour : adj[topNode]){  // Top Node ke neighbours nikalo
            if(nodeDistance + neighbour.second < dist[neighbour.first]){  // agar (curr node ka distance + distance to neigbour node) is less then dist of neigbour node which is previously stored in dist then
                auto record = st.find({dist[neighbour.first],neighbour.first});  // Agar record mein same node already present then delete the previous node and put new record with less distance
                
                // If record found then erase it
                st.erase(record);  // Agar record nahi mila toh kuch erase nahi hoga

                // distance Update Karo
                dist[neighbour.first] = nodeDistance + neighbour.second;  // new distance to neigbour is distance to curr node + ditance to neigbour node from curr
                parent[neighbour.first] = topNode;

                // Push Record in set
                st.insert({dist[neighbour.first], neighbour.first}); // neigbour ke distance aur neighbour node ko set mein push kardo 
            }
        }
    }
    
    if(dist[n] == INT_MAX){  // If dist mein nth node par INT_MAX hai means it is disconnected to the main graph return -1
        return {-1};
    }
    
    vector<int> path; 
    int node = n;  // node points to the last node in the graph
    
    while(parent[node] != node){  // Jabtak parent ka node node ke barabar na ho jaye taktak loop
        path.push_back(node);  // path mein node ko push kardo
        node = parent[node];   // node ko update kardo with it's parent
    }
    
    path.push_back(src);   // Last mein src push kardo kyuki it is the final ancestor
    reverse(path.begin(), path.end());  // Reverse kardo kyuki hamne piche se mapping kia hai
    
    path.insert(path.begin(), dist[n]);  // Ab path mein n ki jo dist nikli hai usse daldo
    
    return path;
}

int main(){
    
    int n = 5;
    
    vector<vector<pair<int,int>>> adj(n+1);
    
    // Directed Graph
    adj[1] = {{4,1},{2,2}};
    adj[2] = {{3,4},{5,5}};
    adj[3] = {{5,1}};
    adj[4] = {{3,3}};
    adj[5] = {};

    int src;
    cout<<"Enter Source Node: ";
    cin>>src;

    vector<int> ans = shortestPath(adj,src,n);
    cout<<"Shortest Path in the Graph from Source to Destination is: ";
    for(int i=0;i<1;i++){
        cout<<ans[i]<<" -> ";
    }

    for(int i=1;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}