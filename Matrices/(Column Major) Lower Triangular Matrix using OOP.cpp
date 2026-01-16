#include<iostream>
using namespace std;

class LowerTriangular{
	private:
		int *A;
		int n;
		
	public:
		LowerTriangular(int size){
			n = size;
			A = new int[n*(n+1)/2];    // Allots only required spaces,saving memory
			
			for(int i=0;i<n;i++){
				A[i] = 0;  // Initially initialize all elements as 0
			}
		}
		
		~LowerTriangular(){
			delete []A;
		}
		
		void Set(int i, int j, int x){
			if(i>=j){
				A[n*(j-1) - ((j-1)*(j-2))/2 + (i-j)] = x;
			}
		}
		
		int Get(int i, int j);
		void Display();
};

int LowerTriangular::Get(int i, int j){
	if(i>=j){
		return A[n*(j-1) - ((j-1)*(j-2))/2 + (i-j)];
	}
	else{
		return 0;
	}
}

void LowerTriangular::Display(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>=j){
				cout<<A[n*(j-1) - ((j-1)*(j-2))/2 + (i-j)]<<" ";
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
	cout<<"Enter Dimesion of the Matrix: ";
	cin>>size;
	
	LowerTriangular  m(size);
	cout<<"Enter Elements column by column: "<<endl;
	for(int j=1;j<=size;j++){
		for(int i=j;i<=size;i++){
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
