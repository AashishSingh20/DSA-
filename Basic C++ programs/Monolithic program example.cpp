#include<iostream>
using namespace std;

int main(){
	int length = 0, breadth = 0;
	
	cout<<"Enter length and breadth:";
	cin>>length>>breadth;
	
	int area = length*breadth;
	cout<<"Area of rectangle is:"<<area<<endl;

    int perimeter = 2*(length+breadth);
    cout<<"Perimeter of rectangle is:"<<perimeter<<endl;
    
    return 0;
}
