#include<iostream>
using namespace std;

int main(){
    // int n;
    // cout<<"Enter size of Array: ";
    // cin>>n;

    // int **arr = new int*[n];   // When row and column is of same size
    // for(int i=0;i<n;i++){
    //     arr[i] = new int[n];
    // }
// Creation of 2D Array is completed here

    int row,col;
    cin>>row>>col;

    int **arr = new int*[row];  // When Row and column is of different size
    for(int i=0;i<row;i++){
        arr[i] = new int[col];
    }

    cout<<"Enter Array Elements: ";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    
    cout<<"Output: "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Releasing Memory
    for(int i=0;i<row;i++){ // First deleting all columns associated with each pointer(rows)
        delete[]arr[i];   
    }
    delete[]arr;  // Then deleting all pointers(rows)
}