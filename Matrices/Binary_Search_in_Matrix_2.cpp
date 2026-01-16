#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& arr,int target, int row, int col){
    int rowIndex = 0;
    int colIndex = row*col-1;

    while(rowIndex < row && colIndex >= 0){
        int element = arr[rowIndex][colIndex];  // Converts linear index into matrix form

        if(element == target){
            return 1;
        }

        else if(element < target){
            rowIndex++;
        }

        else{
            colIndex--;
        }
    }
    return 0;
}

int main(){
    int rows = 3, cols = 3;
    vector<vector<int>> arr(rows, vector<int>(cols));   // Defines a matrix in vector format

    cout << "Input: " << endl;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            cin>>arr[row][col];
        }
    }

    cout<<"Matrix: "<<endl;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
}