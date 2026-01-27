#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int celebrity(vector<vector<int>> &people, int n){
    
    // Step 1:- Find Potential Celebrity
    int i = 0;
    int j = n-1;
    while(i < j){   // Loop until i is less than j
        if(people[i][j] == 1){   // Check if 'i' knows 'j', if he knows it means 'i' cannot be a celebrity 
            i++;   // Increment of i check other candidate
        }
        else{    // If 'i' doesn't know 'j' then 'j' cannot be a celebrity
            j--;   // Decrement j
        }
    }

    // Step 2:- Row check verify
    int candidate = i;   
    for(int k = 0;k<n;k++){
        if(k != candidate && people[candidate][k] == 1){
            return -1;
        }
    }

    // Step 3:- Column Check verify
    for(int k=0;k<n;k++){
        if(k != candidate && people[k][candidate] == 0){
            return -1;
        }
    }

    return candidate;
}

int main(){
    int n;
    cout<<"Enter Number of people at the Party: ";
    cin>>n;

    if(n == 0){
        cout<<"Invalid number of People!";
        return 0;
    }

    vector<vector<int>> people(n, vector<int> (n));
    cout<<"Enter Number in Binary: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>people[i][j];
        }
    }

    cout<<"Array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<people[i][j]<<" ";
        }
        cout<<endl;
    }

    int celeb = celebrity(people,n);

    if(celeb == -1){
        cout<<"There is no Celebrity at the Party"<<endl;
    }
    else{
        cout<<"Celebrity is Person: "<<celeb<<endl;
    }
}