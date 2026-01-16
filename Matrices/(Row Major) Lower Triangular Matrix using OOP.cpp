#include<iostream>
using namespace std;

class LowerTriangular{
	private:
		int *A;
		int n;
		
	public:	
		LowerTriangular(int size){
			n = size;
			A = new int[n*(n+1)/2];
			
			for(int i=0;i<n;i++){
				A[i] = 0;
			}
		}
		
		~LowerTriangular(){
			delete[]A;
		}
		
		void Set(int i, int j, int x){
			if(i>=j){
				A[i*(i-1)/2+j-1] = x;
			}
		}
		
		int Get(int i, int j);
		void Display();
};

int LowerTriangular::Get(int i, int j){
	if(i>=j){
		return A[i*(i-1)/2+j-1];
	}
	
	else{
		return 0;
	}
}

void LowerTriangular::Display(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>=j){
				cout<<A[i*(i-1)/2+j-1]<<" ";
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
}

int main(){
	int size;
	cout<<"Enter Dimension of Matrix: ";
	cin>>size;
	
	LowerTriangular m(size);
	
	cout<<"Enter Elements row by row: "<<endl;
	for(int i=1;i<=size;i++){
		for(int j=1;j<=i;j++){
			int x;
			cin>>x;
			m.Set(i,j,x);
		}
	}
	cout<<endl;
	m.Display();
	
	cout<<"Element at (2,1): "<<m.Get(2,1);
}
