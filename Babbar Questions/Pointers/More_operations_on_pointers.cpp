#include<iostream>
using namespace std;

int main(){

    int num = 5;
    int *p = &num;
    cout<<"Value before increment: "<<num<<endl;
    (*p)++;   // *p points to the actual value in num so increasing it will affect num(pointer does not create a copy)
    cout<<"Value after increment: "<<num<<endl;

    int *q = p;  // Copying Pointer p to q
    cout<<"Value of pointer p: "<<p<<" - "<<*p<<endl;
    cout<<"Value of pointer q: "<<q<<" - "<<*q<<endl;
}