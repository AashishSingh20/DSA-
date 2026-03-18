#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int> &cost, int n){
    // Base Case
    if(n==0){  // I coming from 1st Stair
        return cost[0];
    }
    if(n == 1){  // If coming from 2nd Stair
        return cost[1];
    }

    int ans = cost[n] + min(minCost(cost,n-1),minCost(cost,n-2));

}

int main(){

    int n;
    cout<<"Enter number of Stairs: ";
    cin>>n;

    vector<int> cost(n);
    cout<<"Enter cost of each Stair: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>cost[i];
    }
    cout<<endl;

    int ans = min(minCost(cost,n-1),minCost(cost,n-2));
    cout<<"Minimum cost to climb all chairs is: "<<ans<<endl;
}