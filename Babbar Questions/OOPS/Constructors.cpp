#include<iostream>
using namespace std;

class Hero{ 
    private: 
        char type;

    public:  
        int health;  
        char level;
    

    int getHealth(){ 
        return health;
    }

    char getType(){  
        return type;
    }

    void setHealth(int h){ 
        health = h;
    }

    void setType(char t){
        type = t;
    }

// Default Constructor // Kuch nhi bhi likhunga toh yeh exist karega agar koi bhi constructor khud se bana liya toh default constructor mar jayega
    Hero(){
        cout<<"Constructor Called"<<endl;
    }

// Parameterized Constructor
    Hero(int health){
        this->health = health;   // This stores the address of health
    }

    void print(){
        cout<<"Health: "<<this->health<<endl;
        cout<<"Type: "<<this->type<<endl;
    }

// Copy Constructor
    Hero(Hero& temp){   // Yeh signify kar raha hai ki niche kaise copy ho raha hai yeh nahi bhi likhenge toh chalega agar ham copy constructor mein kuch changes karna chahte hai toh yeh use karo 
        cout<<"Copy Constructor Called"<<endl;
        this->health = temp.health;
        this->type = temp.type;
    }
};

int main(){
    // cout<<"Hi"<<endl;
    // Hero Ram;
    // cout<<"Hello"<<endl;

    // Hero *h = new Hero;  // Static ya Dynamic call dono mein same constructor hi call hoga

// Copy Constructor
    Hero S;
    S.setHealth(70); 
    S.setType('E');
    S.print();

    Hero A(S);   // Yaha Constructor S, A mein copy ho gaya
    A.print();
    // A.health = S.health;
    // A.level = S.level;
  
}