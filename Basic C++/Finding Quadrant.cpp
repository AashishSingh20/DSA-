#include<iostream>
using namespace std;

int main(){
	int a,b;
	cout<<"Enter number on X-axis: ";
	cin>>a;
	cout<<"Enter number on Y-axis: ";
	cin>>b;
	
	if(a>0 && b>0){
		cout<<"Graph lies in 1st Quadrant";
	}
	else if(a<0 && b>0){
		cout<<"Graph lies in 2nd Quadrant";
	}
	else if(a<0 && b<0){
		cout<<"Graph lies in 3rd Quadrant";
	}
	else if(a>0 && b<0){
		cout<<"Graph lies in 4th Quadrant";
	}
	else{
		cout<<"Graph lies at origin";
	}
}
