#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &wt, vector<int> &val, int n, int capacity){

    // Step 1:
    vector<int> curr(capacity+1,-1);  // dp[idx]  Curr vector apne se pehle wale vector par dependent hai

    // Analyse Base Case
    for(int w = wt[0];w<=capacity;w++){  // Start loop from weight at 0th index till capacity
        if(wt[0] <= capacity){  // Agar weight of 0th index <= capacity, prev ke w mein value put kardo
            curr[w] = val[0];
        }
        else{
            curr[w] = 0;  // Else  prev ke w mein mein 0 daldo(Matlab not possibe to put in knapsack)
        }
    }

    // Step 2: Handle Other Cases
    for(int idx=1; idx<n; idx++){
        for(int w=capacity;w>=0;w--){
            int include = 0;

            if(wt[idx] <= w){
                include = val[idx] + curr[w - wt[idx]];
            }

            int exclude = 0 + curr[w];

            curr[w] = max(exclude,include);  
        }
    }
    
    return curr[capacity];
}

int main(){
    int n;
    cout<<"Enter Number of Items: ";
    cin>>n;

    int w;
    cout<<"Enter the weight which can be filled in knapsack: ";
    cin>>w;

    vector<int> wt(n);
    cout<<"Enter Weight of all Items: ";
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    vector<int> val(n);
    cout<<"Enter Value of all Items: ";
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    int ans = solve(wt,val,n,w);
    cout<<"Maximum Value of Items the thief can put in Knapsack is: "<<ans<<endl;
}