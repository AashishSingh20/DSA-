#include<iostream>
using namespace std;

struct Matrix{
	int *A;
	int n;
};

void Set(struct Matrix *m, int i, int j, int x){
	if(i>=j){
		m->A[m->n*(j-1) - ((j-1)*(j-2))/2 + (i-j)] = x;
	}
}

int Get(struct Matrix m, int i, int j){
	if(i>=j){
		return m.A[m.n*(j-1) - ((j-1)*(j-2))/2 + (i-j)];
	}
	else{
		return 0;
	}
}

void Display(struct Matrix m){
	for(int i=1;i<=m.n;i++){
		for(int j=1;j<=m.n;j++){
			if(i>=j){
				cout<<m.A[m.n*(j-1) - ((j-1)*(j-2))/2 + (i-j)]<<" ";
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
}

int main(){
	struct Matrix m;
	cout<<"Enter the dimensions of the matrix: ";
	cin>>m.n;
	
	m.A = new int[m.n * (m.n+1) / 2];
	
	int x;
	cout<<"Enter Elements of lower Triangular Matrix(column wise): "<<endl;
	for(int j=1;j<=m.n;j++){
		for(int i=j;i<=m.n;i++){
			cin>>x;
			Set(&m,i,j,x);
		}
	}
		cout<<endl;
		Display(m);
}
