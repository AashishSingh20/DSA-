#include<iostream>
using namespace std;
struct Rectangle
{
	int length;
	int breadth;
};


int main()
{
	struct Rectangle r1={4,6};
	cout<<"The size of structure is:"<<sizeof(r1)<<endl;
	cout<<"The area of rectangle is:"<<r1.length*r1.breadth<<endl;
	return 0;
}
