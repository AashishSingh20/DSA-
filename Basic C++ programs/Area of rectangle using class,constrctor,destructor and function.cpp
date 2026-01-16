#include<iostream>
using namespace std;

class Rectangle{
	private:
		int length;
		int breadth;
	
	public:
	    Rectangle(){
	    	length=0;
	    	breadth=0;
		}	
		
		Rectangle(int l, int b){
			length=l;
			breadth=b;
		}
		
		int area(){
			return length*breadth;
		}
		
		int perimeter(){
			return 2*(length+breadth);
		}
		
		void setLength(int l){
			length = l;
		}
		
		void setBreadth(int b){
			breadth = b;
		}
		
		int getLength(){
			return length;
		}
		
		int getBreadth(){
			return breadth;
		}
		
		~Rectangle(){
		}
};

int main()
{
	int a,b;
	cout<<"Enter length:";
	cin>>a;
	
	cout<<"Enter breadth:";
	cin>>b;
	Rectangle r(a,b);
	
	cout<<"Area of Rectangle is:"<<r.area()<<endl;
	cout<<"Perimeter of Rectangle is:"<<r.perimeter()<<endl;
	
	int x;
	cout<<"Enter new length:";
	cin>>x;
	r.setLength(x);
	
	cout<<"Now Area of Rectangle is:"<<r.area()<<endl;
	cout<<"Now Perimeter of Rectangle is:"<<r.perimeter()<<endl;
	
	return 0;
}
