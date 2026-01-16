#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter array size: ";
	cin>>n;
	int arr[n];
	
	cout<<"Enter Array Elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int solution = 0;
	for(int i=0;i<n;i++){
		solution = solution^arr[i];  // Agar har elements twice hai except 1 element to yaha tak hi karna(Unique element dega)
	}
	
	for(int i=1;i<n;i++){
		solution = solution^i;  // Agar 1 element hi twice hai toh isse use karna(Repeated element dega)
	}
	return solution;
}
