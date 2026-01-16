/* Eg:In 3X4 Matrix  1 2 3 4              1 5 9
                     5 6 7 8        -->>  10 6 2
                     9 10 11 12           3 7 11        
                                          12 8 4       */        

#include<iostream>
using namespace std;

int main(){
    int arr[3][4];

    cout << "Input: " << endl;
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 4; col++){
            cin>>arr[row][col];
        }
    }

    cout<<"Output: "<<endl;
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 4; col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    cout<<"Wave Output: "<<endl;
    for(int col = 0;col<4;col++){
        if(col%2 == 0){
            for(int row = 0;row<3;row++){
                cout<<arr[row][col]<<" ";
            }
        }
        else{
            for(int row = 2;row>=0;row--){
                cout<<arr[row][col]<<" ";
            }
        }
        cout<<endl;
    }
}
