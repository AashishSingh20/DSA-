#include<iostream>
using namespace std;

int main(){
	int arr[] = {3,8,6,2,1};
	int x = 5;
	int count = 0;
	cout<<"Array: ";
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<5;i++){
    	if(arr[i]>x){
    		count += 1;
		}
    }
    cout<<"Number of elements greater than x is: "<<count;
}
