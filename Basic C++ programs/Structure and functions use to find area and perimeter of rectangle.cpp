#include<iostream>
using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

void initialize(Rectangle *r,int l,int b){
	r->length=l;
	r->breadth=b;
}

int area(Rectangle r){
	return r.length*r.breadth; 
}

int perimeter(Rectangle r){
	int p= 2*(r.length+r.breadth);
	return p;
}

int main()
{
	Rectangle r={0,0};
	
	int l,b;
	cout<<"Enter length and breadth of Rectangle:";
	cin>>l>>b;
	
	initialize(&r,l,b);
	
	int a=area(r);
	int peri=perimeter(r);
	
	cout<<"Area of Rectangle is:"<<a<<endl;
	cout<<"Perimeter of Rectangle is:"<<peri<<endl;
	
	return 0;
}
