#include<iostream>
using namespace std;

struct Rectangle{
	int length;
	 int breadth;
};

int main(){
	struct Rectangle *p;
	p= new Rectangle;
	p->length=2;
	p->breadth=4;
	
	cout<<p->length<<endl;
	cout<<p->breadth<<endl;
	
	return 0;
}
