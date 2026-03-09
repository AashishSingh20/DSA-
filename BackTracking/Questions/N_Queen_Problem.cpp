#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    // Case
    int x = row;
    int y = col;
    
    // check for same row
    while(y >= 0){
        if(board[x][y] == 1){  // Agar element same row mein hai toh us row ke column mein check karo
            return false;  // if queen present mile then return false
        }
        y--;
    }

    x = row;  // Reset x and y
    y = col;
    // Check for Upper Left Diagonal
    // Upward diagonal moving right to left(pehle wale ko check karna hai toh piche wale ko check kar rahe hai  
    // Aage wale ko check karne ki jarurat nahi kyuki there is no problem in next col 
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){  // Agar element same row mein hai toh us row ke column mein check karo
            return false;  // if queen present mile then return false
        }
        x--;
        y--;
    } 

    x = row;  // Reset X and y
    y = col;
    // Check for Lower Left Diagonal
    while(x < n && y >= 0){
        if(board[x][y] == 1){  // Agar element same row mein hai toh us row ke column mein check karo
            return false;  // if queen present mile then return false
        }
        x++;
        y--;
    } 
    return true;

}

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n){

    vector<int> temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);  // temp ke andar saari values daldo
        }
    }

    ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    // Base Case
    // If col == n means matrix is completely traversed and filled so add solutions
    if(col == n){
        addSolution(board,ans,n);
        return; 
    }

    // Solve 1 case Recursion will handle the rest

    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            // If safe 
            board[row][col] = 1;
            solve(col+1,ans,board,n);
            // Backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n){

    // Creating a Board to simulate placing of queens
    vector<vector<int>> board(n,vector<int> (n,0));
    // Stores answer
    vector<vector<int>> ans;
    solve(0,ans,board,n);

    return ans;
}

int main(){
    int n;
    cout<<"Enter Number of Queens: ";
    cin>>n;

    vector<vector<int>> ans = nQueen(n);
    cout<<"Possible Ways to place a Queen on Chess Board: "<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}