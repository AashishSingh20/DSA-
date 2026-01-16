#include<iostream>
using namespace std;

add(int a,int b){
	int c;
	c=a+b;
	
	return c;
}
	
int main(){
	int x,y,sum;
	cout<<"Enter the value of x:";
	cin>>x;
	cout<<"Enter the value of y:";
	cin>>y;
	
	sum=add(x,y);
	cout<<"The Sum of the two numbers is:"<<sum<<endl;   
	
	return 0;  
   }	
