#include<iostream>
using namespace std;

int main(){
	int arr[5][5];
	cout<<"After Storing 10 at every index: "<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			arr[i][j] = 10;
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
    }
}
