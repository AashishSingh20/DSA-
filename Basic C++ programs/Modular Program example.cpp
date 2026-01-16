#include<iostream>
using namespace std;

int area(int length,int breadth){
	return length*breadth;
}

int perimeter(int length, int breadth){
	int p=2*(length+breadth);
	return p;
}

int main()
{  int length = 0, breadth = 0;

   cout<<"Enter length and breadth of Rectangle:";
   cin>>length>>breadth;
   
   int a = area(length,breadth);
   int peri = perimeter(length, breadth);
   
   cout<<"Area of Rxectangle is:"<<a<<endl;
   cout<<"Perimeter of Rectangle is:"<<peri;
   
   return 0;
}
