#include<iostream>
using namespace std;

int main(){
	int arr[] = {1,2,3,4,5};
	cout<<"Array: ";
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Updated Array: ";
	for(int i=0;i<5;i++){
	   if(i%2!=0){
	   	cout<<arr[i]*2<<" ";
	   }
	   else{
	   	cout<<arr[i]+10<<" ";
	   }
	}
}
