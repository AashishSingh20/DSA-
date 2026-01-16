#include<iostream>
using namespace std;

int main(){
	int x = 3;
	int y = 6;
//	cout<<x<<" "<<y<<endl; // Swap using Extra Variable temp
//	int temp = x;
//	x = y;
//	y = temp;
//	cout<<x<<" "<<y<<endl;
	
	cout<<x<<" "<<y<<endl;  // Swap Without using Extra Variable
	x = x+y;
	y = x-y;
	x = x-y;
	cout<<x<<" "<<y<<endl;
}
