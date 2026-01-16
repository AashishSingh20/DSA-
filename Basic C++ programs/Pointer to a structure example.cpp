#include<iostream>
using namespace std;
struct Rectangle {
	int length;
	int breadth;
};

int main(){
    Rectangle r={10,20};    //In C++ you don't need to use struct before Rectangle while in C you have to.
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;
    
    
    Rectangle *p=&r;
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;
    
    return 0;	
 } 
