#include<iostream>
using namespace std;

int fib(int n){      //Completd by using loops
	int t0=0,t1=1,s;
	
	if(n<=1){
		return n;
	}
	
	for(int i=2;i<=n;i++){
		s=t0+t1;
		t0=t1;
		t1=s;
	}
	return s;
}

int rfib(int n){    //Completed by using recursion
	if(n<=2){
		return n-1;
	}
	else{
		return rfib(n-1)+rfib(n-2);  
	}
}

int F[10];      //Completed using memoization
int mfib(int n){
	if(n<=1){
		F[n]=n;
		return n;
	}
	else{
		if(F[n-2]==-1){
			F[n-2]= mfib(n-2);}
		if(F[n-1]==-1){
			F[n-1]= mfib(n-1);	}
	}
	F[n]=F[n-2]+F[n-1];
	return F[n];
}

int main(){
	int a;
	cout<<"Enter the index of the number:";
	cin>>a;
	cout<<"Answer:"<<fib(a)<<endl;
	cout<<"Answer:"<<rfib(a)<<endl;
	
	for(int i=0;i<10;i++){
		F[i]=-1;
	}
	cout<<"Answer:"<<mfib(a)<<endl; 
	return 0;
}


// T.C => O(2^n)
// S.C => O(n)