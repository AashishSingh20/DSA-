#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;
	
	// 1, 3 ,5, 7, 9,...
//	// METHOD 1
//	for(int i = 1;i<=2*n-1;i+=2){ // nth term is found by using an = a+(n-1)d formula
//		cout<<i<<endl;
//	}
//	
	//METHOD 2
	int a = 1;
	for(int i=1;i<=n;i++){
		cout<<a<<endl;
		a+=2;
	}
}
