#include<iostream>
#include<vector>
using namespace std;
#include <bits/stdc++.h> 
    
bool isSafe(int row, int col, vector<vector<int>> &board, int val){
    int n = board.size();
    for(int i=0;i<9;i++){
        // Row check
        // Agar board ka row mein koi bhi element val ke barabar hai toh return false
        if(board[row][i] == val){
            return false;
        }
        // column check
        if(board[i][col] == val){
            return false;
        }
        
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board){
    
    int n = board.size();
    
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            // If Cell is Empty
            if(board[row][col] == 0){
                // Check by putting number from 1 to 9
                for(int val = 1; val <= 9; val++){
                    // Agar Safe hai toh put the value in the empty index
                    if(isSafe(row,col,board,val)){
                        board[row][col] = val;
                        
                        // Recursive Call
                        bool furtherSolutionsPossible = solve(board);
                        
                        if(furtherSolutionsPossible){
                            return true;
                        }
                        else{
                            // Backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                // If no value works for the current cell
                return false;
            }
        }
    }
    return true;  // Correct numbers are inserted in the sudoku
}
    
void solveSudoku(vector<vector<int>>& sudoku){
    solve(sudoku);
}

int main(){
    // It is a 9X9 Matrix
    cout<<"Enter Elements into Sudoku: ";
    vector<vector<int>> ans;
    for(int i=1;i<=9;i++){
        vector<int> col;
        for(int j=1;j<=9;j++){
            int data;
            cin>>data;
            col.push_back(data);
        }
    ans.push_back(col);
    }

    solveSudoku(ans);

    cout<<"Solved Sudoku: ";
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}