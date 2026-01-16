#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;
	int r;
	cout<<"Enter r: ";
	cin>>r;
	
	int a = 1;
	for(int i=1;i<=n;i++){
	   a *= i;
	}
	
	int b = 1;
	for(int i=1;i<=r;i++){
	   b *= i;
    }
    
	int c = 1;
	for(int i=1;i<=n-r;i++){
	   c *= i; 
    }
    cout<<"Combination of nCr is: "<<a/(b*c)<<endl;
}
