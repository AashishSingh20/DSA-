#include<iostream>
using namespace std;

int main(){
	int *p,*q;  // We cannot directly increase size of array so we use store the vales in an array with extra space
	
	p = new int[5];
	p[0]=6; p[1]=8; p[2]=1; p[3]=0; p[4]=5;
	
	q = new int[10];
	for(int i=0;i<5;i++){
		q[i] = p[i];
	}
	cout<<endl;
	
	delete []p;
	p = q;
	q = NULL;
	
	for(int i=0;i<5;i++){
		cout<<p[i]<<" ";
	}
	
}
