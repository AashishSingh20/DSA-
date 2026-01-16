#include<iostream>
using namespace std;

class Human{   // Parent Class
    public:
        int height;
        int weight;
        int age;
    
    int getAge(){
        return age;
    }

    int setWeight(int w){
        this->weight = w; 
    }
};

class Male: public Human{   // Child Class

    public:
        string color;

    void Study(){
        cout<<"Male is Studying.";
    }
};

int main(){
    Male object1;
    cout << object1.age << endl;   // Age is inherited from parent class into child class same for he 3 below
    object1.setWeight(76);  
    cout << object1.weight << endl;
    cout << object1.height << endl;
    
    cout << object1.color << endl;
}