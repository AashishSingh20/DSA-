#include<iostream>
using namespace std;

int main(){
	float P,R,T;
	cout<<"Enter Principal Amount: Rs ";
	cin>>P;
	cout<<"Enter Rate of Interest: ";
	cin>>R;
	cout<<"Enter Time Period: ";
	cin>>T;
	
	float SI = (P*R*T)/100;
	cout<<"Simple Interest: "<<"Rs "<<SI<<endl;
}
