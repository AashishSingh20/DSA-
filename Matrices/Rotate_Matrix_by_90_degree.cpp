/* Eg:   1 2 3          7 4 1
         4 5 6    -->>  8 5 2
         7 8 9          9 6 3   */

#include<iostream>
#include<vector>
using namespace std;


void rotateMatrix(vector<vector<int>>& arr, int rows, int cols){

    int startingCol = 0;  // This is used to find starting index of the column
    int endingCol = cols-1;   // This is the ending index of column (both startingCol and endingCol help to swap columns after transpose)
    for(int row = 0; row < rows; row++){
        for(int col = row+1; col < cols; col++){
            swap(arr[row][col], arr[col][row]);  // Converts rows into columns and columns into rows(transpose)
        }
    }

    while(startingCol < endingCol){
        for(int row = 0; row < rows; row++){
            swap(arr[row][startingCol], arr[row][endingCol]);  // Swaps columns 1 and last then 2nd and 2nd last and so on
        }
        startingCol++;
        endingCol--;
    }

    cout<<"After Rotating Matrix by 90 degree: "<<endl;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
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

    rotateMatrix(arr,rows,cols);
}