#include<iostream>
using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

int changelength(Rectangle *p,int l){
	p->length=l;
	return l;
}

int main(){
	struct Rectangle r={10,4};
	cout<<"Length:"<<r.length<<endl;
	changelength(&r,20);
	cout<<"Updated length:"<<r.length<<endl;
		
	return 0;
}
