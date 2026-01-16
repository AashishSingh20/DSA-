#include<iostream>
using namespace std;

int fact(int x){
	int f = 1;
	for(int i=1;i<=x;i++){
		f*=i;
	}
	return f;
}

int nCr(int n,int r){
	int a = fact(n);
	int b = fact(r);
	int c = fact(n-r);
	
    return a/(b*c);
}

int main(){
	int length;
	cout<<"Enter length: ";
	cin>>length;
	
	for(int i=0;i<=length;i++){
		for(int j=0;j<=length-i;j++){
		    cout<<"  ";
		}
		for(int j=0;j<=i;j++){
			cout<<nCr(i,j)<<"   ";
		}
	   cout<<endl;
	}
}
