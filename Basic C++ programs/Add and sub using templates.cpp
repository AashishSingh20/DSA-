#include<iostream>
using namespace std;

template <class T>
class Arithematic{
	private:
		T a;
		T b;
		
	public:
	    Arithematic(T a,T b);
		T add();
		T sub();	
};

template <class T>
Arithematic<T>::Arithematic(T a,T b){
	this->a=a;
	this->b=b;
}

template <class T>
T Arithematic<T>::add(){
	T c;
	c= a+b;
	return c;
}

template <class T>
T Arithematic<T>::sub(){
	T c;
	c= a-b;
	return c;
}

int main(){
	//For integers
	int x,y;
	cout<<"Enter two integer numbers:";
	cin>>x>>y;
	Arithematic<int> ar(x,y);
	
	cout<<"Addition of two numbers is:"<<ar.add()<<endl;
	cout<<"Subtraction of two numbers is:"<<ar.sub()<<endl;
	
	//For floating-point numbers
	float x1,y1;
	cout<<"Enter two floating-point numbers:";
	cin>>x1>>y1;
	Arithematic<float> ar1(x1,y1);
	
	cout<<"Addition of two numbers is:"<<ar1.add()<<endl;
	cout<<"Subtraction of two numbers is:"<<ar1.sub()<<endl;
	
	return 0;
}
