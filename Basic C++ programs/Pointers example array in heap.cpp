#include<iostream>
using namespace std;

int main()
{
	int *p;
	p= new int[5];
	p[0]=12;
	p[1]=14; 
	p[2]=16; 
	p[3]=18; 
	p[4]=20;
	
  for(int i=0;i<5;i++)
  cout<<p[i]<<endl;
  
  return 0;

}
