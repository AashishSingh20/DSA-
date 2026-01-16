#include<iostream>
using namespace std;

double e(int x, int n){
	static int s=1;
	if(n==0){
		return s;
	}
	else{
		s=1+x*s/n;
	return e(x,n-1);
	}
}

int main(){
	int x,n;
	cout<<"Enter value of x:";
	cin>>x;
	cout<<"Enter value of n:";
	cin>>n;
	
	cout<<"Result:"<<e(x,n)<<endl;
	return 0;
}
