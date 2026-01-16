#include<iostream>
using namespace std;

class Animal{  // Parent Class 'Animal'

    public:
        int age;
        int weight;

    public:
        void speak(){
            cout<<"Speaking.";
        }
};

class Dog: public Animal{   // Child Class 'Dog' accessing 'Animal'
    
};

class DoberMan: public Dog{  // Child Class 'DoberMan' accessing 'Dog'

};

int main(){
    DoberMan d;
    d.speak();
}