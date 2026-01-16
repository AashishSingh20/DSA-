#include<iostream>
using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

void initialize(struct Rectangle *r,int l,int b){
	r->length=l;
	r->breadth=b;
}

int area(struct Rectangle r){
	return r.length*r.breadth;
}

void changelength(struct Rectangle*r,int l){
	r->length=l;
}

int main(){
	struct Rectangle r;
	
	initialize(&r,20,30);
	cout<<"Length:"<<r.length<<endl<<"Breadth:"<<r.breadth<<endl;
	
	cout<<"Area of rectangle is:"<<area(r)<<endl;
	
	changelength(&r,12);
	cout<<"After changing the length, length is equal to:"<<r.length<<endl;
	
	return 0;
	
}
