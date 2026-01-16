#include<iostream>
#include<string>
using namespace std;

int main(){
	string A;
	cout<<"Enter 1st string: ";
	cin>>A;
	string B;
	cout<<"Enter 2nd string: ";
	cin>>B;
	
	
	int i = 0; 
	int j = 0;
	while(A[i]<A.length() && B[j]<B.length()){
		i++;
		j++;
		if(A[i]!=B[j]){
			break;
		}
	}
		
		if(A[i]==B[j]){
			cout<<"Both Strings are Equal.";
		}
		else if(A[i]>B[j]){
			cout<<"A is greater than B.";
		}
		else if(A[i]<B[j]){
			cout<<"B is greater than A.";
		}
}
