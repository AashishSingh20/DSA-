#include<iostream>
using namespace std;

bool isPossible(int arr[][4],int target, int row, int column){  // When passing 2D Arrays as paramater you should atleast mention it's column size
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            if(arr[row][column] == target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[3][4];

    cout<<"Input: "<<endl;
    for(int row=0;row<3;row++){   // Taking input row-wise
        for(int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }

    cout<<"Output: "<<endl;
    for(int row=0;row<3;row++){   // Printing output row-wise
        for(int col=0;col<4;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    int target;
    cout<<"Enter target you want to find: ";
    cin>>target;

    if(isPossible(arr, target, 3, 4)){
        cout<<"Target is Present.";
    }
    else{
        cout<<"Target is not Present.";
    }
}