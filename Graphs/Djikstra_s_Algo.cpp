#include<bits/stdc++.h>
using namespace std;

vector<int> djikstra(vector<vector<pair<int,int>>> &adj, int src, int n){

    // Creation of Distance Array with INT_MAX values initially
    vector<int> dist(n,INT_MAX);

    // Creation of Set
    set<pair<int,int>> st;

    // Initialize distance and set with src node
    dist[src] = 0;
    st.insert({0,src});  // We using set as it store elements in ascensing order so smallest distance is at top

    while(!st.empty()){
        // Fetch top record
        auto top = *(st.begin());  // Top ke andar set ka top element daldo

        int nodeDistance = top.first;  // top ka 1st distance hoga
        int topNode = top.second;   // And top ka second topNode kon hai toh hoga

        // Remove top record
        st.erase(st.begin());

        // Traverse neighbours
        for(auto neighbour : adj[topNode]){  // Top Node ke neighbours nikalo
            if(nodeDistance + neighbour.second < dist[neighbour.first]){  // agar (curr node ka distance + distance to neigbour node) is less then dist of neigbour node which is previously stored in dist then
                auto record = st.find({dist[neighbour.first],neighbour.first});  // Agar record mein same node already present then delete the previous node and put new record with less distance
                
                // If record found then erase it
                st.erase(record);

                // distance Update Karo
                dist[neighbour.first] = nodeDistance + neighbour.second;  // new distance to neigbour is distance to curr node + ditance to neigbour node from curr

                // Push Record in set
                st.insert({dist[neighbour.first], neighbour.first}); // neigbour ke distance aur neighbour node ko set mein push kardo 
            }
        }
    }

    return dist;
}

int main(){
    int n = 4;
    
    vector<vector<pair<int,int>>> adj(n);
    
    // Undirected Graph without weights
    adj[0] = {{1,5},{2,8}};
    adj[1] = {{0,5},{2,9},{3,2}};
    adj[2] = {{0,8},{1,9},{3,6}};
    adj[3] = {{1,2},{2,6}};

    int src;
    cout<<"Enter Source Node: ";
    cin>>src;

    vector<int> ans = djikstra(adj,src,n);
    cout<<"Shortest Path from source node to all nodes is: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}