#include<iostream>
using namespace std;

class A{   // Parent Class
    public:
        void func1(){
            cout<<"Inside Function 1"<<endl;
        }
};

class B: public A{  // Child Class 1
    public:
        void func2(){
            cout<<"Inside Function 2"<<endl;
        }
};

class C: public A{  // Child Class 2
    public:
        void func3(){
           cout<<"Inside Function 3"<<endl;
        }
};

int main(){
    A obj1;
    obj1.func1();   // It can access itself as a parent class

    B obj2;
    obj2.func1();  // It can access it's parent 1
    obj2.func2();  // It can access itself as well

    C obj3;
    obj3.func1();  // It can access it's parent 1
    obj3.func3();  // It can access itself as well
}