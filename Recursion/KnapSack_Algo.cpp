#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &wt, vector<int> &val, int index, int capacity){
    // Base Case
    if(index == 0){   // Ham piche se start kar rahe hai toh index is coming from last to start
        if(wt[0] <= capacity){  // Agar 0th index wale element ka weight KNapsack ki capacity se <= hai toh usse knapsack mein daldo
            return val[0];
        }
        else{    // Else usse knapsack mein mat daalo
            return 0;   
        }
    }

    int include = 0;
    if(wt[index] <= capacity){   // Agar item ka weight knapsack ki capacity se kam hai then include
        include = val[index] + solve(wt,val,index-1,capacity - wt[index]);  // include current val at index and aage ke liye call
    }
        
    int exclude = 0 + solve(wt,val,index-1,capacity);  // Since item is excluded knapsack ki capacity kam nahi hogi

    int ans = max(exclude,include);

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