#include<iostream>
using namespace std;

class UpperTriangular{
	private:
		int *A;
		int n;
		
	public:
		UpperTriangular(int size){
			n = size;
			A = new int[n*(n+1)/2];    // Allots only required spaces,saving memory Non_Zero Elements will be stored here
			
			for(int i=0;i<n*(n+1)/2;i++){
				A[i] = 0;  // Initially initialize all elements as 0
			}
		}
		
		~UpperTriangular(){
			delete []A;
		}
		
		void Set(int i, int j, int x){
			if(i<=j){
				A[n*(i-1) - ((i-1)*(i-2))/2 + (j-i)] = x;
			}
		}
		
		int Get(int i, int j);
		void Display();
};

int UpperTriangular::Get(int i, int j){
	if(i<=j){
		return A[n*(i-1) - ((i-1)*(i-2))/2 + (j-i)];
	}
	else{
		return 0;
	}
}

void UpperTriangular::Display(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i<=j){
				cout<<A[n*(i-1) - ((i-1)*(i-2))/2 + (j-i)]<<" ";
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
	cout<<"Enter Dimension of the Matrix: ";
	cin>>size;
	
	UpperTriangular  m(size);
	cout<<"Enter Elements row by row: "<<endl;
	for(int i=1;i<=size;i++){
		for(int j=i;j<=size;j++){
			int x;
			cin>>x;
			m.Set(i,j,x);
		}
	} 
		cout<<endl;
		m.Display();
	
	int r,c;
	cout<<"Enter Position to Get Element: ";
	cin>>r>>c;
	cout<<"\nThe Element at "<<r<<" , "<<c<<" is: "<<m.Get(r,c);
}
