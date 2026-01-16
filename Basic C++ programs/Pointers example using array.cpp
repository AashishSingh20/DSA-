#include<iostream>
using namespace std;

int main()
{
	int A[5] = {2,4,6,8,10};
	int *p;
	p=A;  // When giving array name to a pointers we don't use "&" symbol as it will atomatically considered as A[0]
//	p=&A[1];    If you are specifying the address in the array then "&" symbol is used


for(int i=0;i<5;i++){
	cout<<A[i]<<endl; //Without using pointer
	cout<<p[i]<<endl; //Using pointer
}
    cout<<"Using pointers:"<<*p<<endl;
	return 0; 
}
