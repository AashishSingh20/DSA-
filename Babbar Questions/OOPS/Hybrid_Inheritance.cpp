// Here we will take hybrid of Multiple and Simple Inheritance
#include<iostream>
using namespace std;

class A{   // Parent Class 'A'
    public:
        void fun1(){
            cout<<"Function 1"<<endl;
        }
};

class B: public A{    // Class 'B' Child of Class 'A'
    public:
        void fun2(){
            cout<<"Function 2"<<endl;
        }
};

class C: public A,public D{   // Class 'C' Child of Class 'A' and 'D'
    public:
        void fun3(){
            cout<<"Function 3"<<endl;
        }
};

class D{
    public:
        void fun4(){
            cout<<"Funcion 4"<<endl;
        }
};


int main(){
    B obj1;   // B and C are child of A so it is an Example of Heirarchical Inheritance
    obj1.fun1();   
    obj1.fun2();

    C obj2;   // C is the child of A and D so it is an Example of Multiple Inheritance
    obj2.fun1();
    obj2.fun3();
    obj2.fun4();
}