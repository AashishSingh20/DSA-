#include<iostream>
#include<climits>   // INT_MIN is in this header file
using namespace std;

int largestRowSum(int arr[][4], int row , int col){
    int maxi = INT_MIN;
    int num = -1;
        for(int row=0;row<3;row++){ 
        int sum = 0;
        for(int col=0;col<4;col++){
            sum += arr[row][col];
        }
        if(sum>maxi){
            maxi = sum;
            num = row;
        }
    }
    cout<<"The Maximum sum is: "<<maxi<<endl;
    return num;
}

void rowSum(int arr[][4], int row, int col){
    for(int row=0;row<3;row++){ 
        int sum = 0;
        for(int col=0;col<4;col++){
            sum += arr[row][col];
        }
        cout<<sum<<endl;
    }
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

    cout<<"Row-wise Sum of the Matrix: "<<endl;
    rowSum(arr,3,4);

    cout<<"Max Row sum is at row: "<<largestRowSum(arr,3,4)<<endl;
}