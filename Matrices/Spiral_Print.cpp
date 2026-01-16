#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& arr, int rows, int cols){
    int count = 0;
    int total = rows*cols;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = rows-1;
    int endingCol = cols-1;
    vector<int> ans;

    while(count < total){
        // Print Starting row
        for(int index = startingCol; count < total && index <= endingCol; index++){  // Yaha row constant hai column change ho raha hai
            ans.push_back(arr[startingRow][index]);
            count++;
        }
        startingRow++;   // Next iteration mein starting row 

        //Print ending column
        for(int index = startingRow; count < total && index <= endingRow; index++){  // Yaha column constant hai row change ho raha hai 
            ans.push_back(arr[index][endingCol]);
            count++;
        }
        endingCol--;

        // Print ending Row
        for(int index = endingCol; count < total && index >= startingCol; index--){  // Yaha par bhi row constant hai column change ho raha hai
            ans.push_back(arr[endingRow][index]);
            count++;
        }
        endingRow--;

        //Print Starting column
        for(int index = endingRow; count < total && index >= startingRow; index--){ // Yaha par bhi column constant hai row change ho raha hai
            ans.push_back(arr[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main(){
    int rows = 3, cols = 4;
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

    cout<<"After Spiral elements: ";
    vector<int> spiral = spiralOrder(arr,rows,cols);

    for(int i = 0;i<spiral.size();i++){
        cout<<spiral[i]<<" ";
    }
    cout<<endl;
}