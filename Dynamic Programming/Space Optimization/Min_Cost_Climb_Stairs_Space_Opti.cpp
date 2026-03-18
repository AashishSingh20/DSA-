#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int> &cost, int n){

    // Step 1:
    int prev1 = cost[0];
    int prev2 = cost[1];

    // Step 2:
    for(int i=2;i<n;i++){
        int curr = cost[i] + min(prev1,prev2);
        prev1 = prev2;
        prev2 = curr;
    }

    // Step 3:
    return min(prev1,prev2);
}

int main(){

    int n;
    cout<<"Enter number of Stairs: ";
    cin>>n;

    vector<int> cost(n);
    cout<<"Enter cost of each Stair: ";
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    cout<<endl;
    
    // 1 100 1 1 1 100 1 1 100 1
    int ans = minCost(cost,n);
    cout<<"Minimum cost to climb all chairs is: "<<ans<<endl;
}