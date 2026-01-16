#include <iostream>
#include<cmath>
using namespace std;

int Prime(int n){
	if(n<1){
		return false;
	}
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cout<<"Enter the number:";
	cin>>n;
	
	if(Prime(n)){
		cout<<"Is a prime number"<<endl;
	}
	else{
		cout<<"Is not a prime number"<<endl;
	}	
	return 0;
}
