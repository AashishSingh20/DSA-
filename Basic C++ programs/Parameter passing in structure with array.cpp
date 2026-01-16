#include<iostream>
using namespace std;

struct Test{
	int A[5];
	int n;
};

void fun(struct Test &t1){   //Here we are Passing array contents with passing by reference method.
	t1.A[0]=2;
	t1.A[1]=4;
}

int main(){
	struct Test t={{1,3,5,6,7},5};
	cout<<"A[0] initially:"<<t.A[0]<<endl<<"A[1] initially:"<<t.A[1]<<endl;
	fun(t);
	cout<<"Updated A[0]:"<<t.A[0]<<endl<<"Updated A[1]:"<<t.A[1]<<endl;
}a
