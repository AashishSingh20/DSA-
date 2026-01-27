#include<iostream>
#include<vector>
using namespace std;

int celebrity(vector<vector<int>> &people, int n){
    for(int i=0;i<n;i++){
        bool isCelebrity = true;   // Initially isCelebrity ko true rakho aur fase tabhi mark karna jab kuch gadbad ho

        // Checking row(i) all should be 0 if he is a celebrity
        for(int j=0;j<n;j++){
            if(i != j && people[i][j] == 1){   // Agar row mein sab 1 hai toh and i != j is used to ignore dynamic values
                isCelebrity = false;   // He knows everyone or someone, he can't be a celebrity mark isCelebrity as false
                break;   // Break out from the inner loop and check other condition
            }
        }

        // Check column(j) all should be 1 except self if he is a celebrity
        for(int j=0;j<n && isCelebrity;j++){   // Loop until j doesn't reach the end of column and isCelebrity is true 
            if(i != j && people[j][i] == 0){   // Agar column mein sab 0 hai and i j ke barabar nahi hai toh
                isCelebrity = false;   // no one knows him or someone doesn't know him mark isCelebrity as false
                break;  // break free from the inner loop
            }
        }
        
        if(isCelebrity){   // If isCelebrity remains true means he is a celebrity
            return i;   // Return index of the celebrity
        }
    }
    return -1;   // If isCelebrity becomes false then return -1 as there is no celebrity in the party
}

int main(){
    int n;
    cout<<"Enter Number of people at the Party: ";
    cin>>n;

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