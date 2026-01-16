#include <iostream>
using namespace std;

class Rectangle	
{ public:
	int length;
	int breadth;

    Rectangle(int l,int b)
    {
  	    length=l;
  	    breadth=b;
	  }
	  
    int area(){
    	return length*breadth;
      }  	 
	 
  	changelength(int l){
  	 	length=l;
	   }
};

int main(){
	int a;
	Rectangle r(20,30);
	cout<<"Length:"<<r.length<<endl<<"Breadth:"<<r.breadth<<endl;
	
	cout<<"Area of Rectangle is:"<<r.area()<<endl;
	r.changelength(10);
	cout<<"After changing length, length is equal to:"<<r.length<<endl;
	
	return 0;
}

