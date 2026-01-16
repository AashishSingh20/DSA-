#include<iostream>
using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

int area (struct Rectangle &r1){  //In call by reference just change r1 to &r1
	r1.length++;
	return r1.length*r1.breadth;
}

int main(){
	struct Rectangle r={10,20};
	cout<<"The area of rectangle is:"<<area(r)<<endl;
	
	return 0;
}
