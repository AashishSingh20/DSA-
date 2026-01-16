#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& arr,int target, int row, int col){
    int start = 0;
    int end = row*col-1;

    while(start <= end){
        int mid = start + (end-start)/2;
        int element = arr[mid/col][mid%col];  // Converts linear index into matrix form

        if(element == target){
            return 1;
        }

        else if(element < target){
            start = mid+1;
        }

        else{
            end = mid-1;
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

    int target;
    cout<<"Enter target: ";
    cin>>target;

    if(searchMatrix(arr,target,rows,cols)){
        cout<<"Target is in the Matrix.";
    }
    else{
        cout<<"Target is not in the Matrix.";
    }
}