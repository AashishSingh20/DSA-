#include<iostream>
#include<vector>
using namespace std;


// Using Tabulation
int main(){
    int n;
    cout<<"Enter the index of Fibonacci Number: ";
    cin>>n;

    // Step 1
    int prev1 = 0;
    int prev2 = 1;

    if(n==0){
        cout<<"Fibonacci Element at nth index is: "<<0<<endl;
        return 0;
    }

    // Step 2
    for(int i=2;i<=n;i++){
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    cout<<"Fibonacci Element at nth index is: "<<prev2<<endl;
}