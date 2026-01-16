#include<iostream>
using namespace std;

class Rectangle{
public:
		int length;
		int breadth;
		
	void initialize(int l, int b){
		length=l;
		breadth=b;
	}	
	
	int area(){
		return length*breadth;
	}
	
	int perimeter(){
		int p = 2*(length+breadth);
		return p;
	}
};

int main()
{
	Rectangle r;
	cout<<"Enter length and breadth:";
	cin>>r.length>>r.breadth;
	
	int a=r.area();
	int peri=r.perimeter();
	
	cout<<"The area of Rectangle is:"<<a<<endl;
	cout<<"The Perimeter of Rectangle is:"<<peri<<endl;
	
	return 0;
}
