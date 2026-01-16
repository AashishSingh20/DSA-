#include<iostream>
using namespace std;

class DiagonalMatrix{
	private:
		int *A;	   // Dynamic array is created to store digonal elements
		int n;    // Size of the Matrix
	
	public:
		DiagonalMatrix(int size){
			n = size;
			A = new int[n];  // Allocate Memory
			
			for(int i=0;i<n;i++){
				A[i] = 0;   // Initializing all elements with 0
			}	
		}
		
		~DiagonalMatrix(){
			delete []A;
		}
		
		void Set(int i, int j, int x){
			if(i==j && i>=1 && i<=n){
				A[i-1] = x;
			}
		}
		
		int get(int i, int j);
		void Display();
};

int DiagonalMatrix::get(int i, int j){
	if(i==j && i>=1 && i<=n){
		return A[i-1];
	}
	else{
		return 0;
	}
}

void DiagonalMatrix::Display(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				cout<<A[i]<<" ";
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
}

int main(){
	DiagonalMatrix m(4);  // Creates 4x4 diagonal Matrix
	m.Set(1,1,4);
	m.Set(2,2,6);
	m.Set(3,3,1);
	m.Set(4,4,11);
	
	cout<<"Matrix: "<<endl;
	m.Display();
	
	cout<<"\nElement at (3,3) is: "<<m.get(3,3)<<endl;
	
}

