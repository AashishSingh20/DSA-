#include<iostream>
using namespace std;

int main(){
	int a[] = {3,45,6,32,65};
	
	int n = sizeof(a)/sizeof(a[0]);
	int b[n];
	cout<<"Elements in Array A: ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Elements in Array B: ";
    for(int i=0;i<n;i++){
    	int j = n-1-i;
    	b[i] = a[j];
    	cout<<b[i]<<" ";
	}
}
