#include<iostream>
using namespace std;

int fact(int n){  //Using normal recursion
	if(n==0){
		return 1;
	}
	else{
		return fact(n-1)*n;
	}
}

int nCr(int n, int r){
	int num,den;
	num =fact(n);
	den = fact(r)*fact(n-r);
	
	return num/den;
}

int NCR(int n,int r){  // Using Pascal's Formula for finding nCr
	if(n==r || r==0){
		return 1;
	}
	else{
		return NCR(n-1,r-1)+NCR(n-1,r);
	}
}

int main(){
	int n,r;
	cout<<"Enter value of n:";
	cin>>n;
	cout<<"Enter value of r:";
	cin>>r;
	
	cout<<"Answer:"<<nCr(n,r)<<endl;
	cout<<"Answer:"<<NCR(n,r)<<endl;
	
	return 0;
}
