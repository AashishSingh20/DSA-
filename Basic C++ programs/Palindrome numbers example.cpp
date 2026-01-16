#include<iostream>
using namespace std;

int reverse(int num){
	int real=num;
	int reverse=0;
	while(num>0){
		reverse=reverse*10+(num%10);
		num=num/10;
	}
	return real==reverse;
}

int main()
{
	int a,n;
	cout<<"Enter number of digits:"<<endl;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"Enter number:";
		cin>>a;
		
		if (reverse(a)){
			cout<<a<<" is same from front and back!"<<endl;
		}
		else{
			cout<<a<<" is not same from front and back!"<<endl;
		}
		
	}		
	return 0;
}
