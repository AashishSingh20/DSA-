#include<bits/stdc++.h>
using namespace std;

int solveRec(int n){
    // Base Case
    if(n == 0){
        return 0;
    }

    int ans = n;    // Answer maximum n hi ho sakta hai agar hamne 1^2 se banaya toh
    for(int i=1;i*i<=n;i++){  // i ko 1 se start karo and i^2 hamesha n se chhota hona chahiye
        ans = min(ans, 1+solveRec(n-i*i));  
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int minSquares = solveRec(n);
    cout<<"Minimum Number of Perfect squares required to sum til n is: "<<minSquares<<endl;
}