#include<iostream>
#include <cstring>
using namespace std;

class Hero{
    private:
        int health;

    public:
        char *name;  // Yaha par name na size allocat mat karo Bad Practice hai
        char level;

// Simple Constructor
    Hero(){
        cout<<"Simple Constructor Called"<<endl;
        name = new char[100];   // hamne name char banaya dynamically 
    }

// Parameterized constructor 
    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }

// Copy Constructor
    Hero(Hero& temp){
        char *ch = new char[strlen(temp.name) + 1];  // New copy of char of size same as original(+1 is added for Null value at last)
        strcpy(ch,temp.name);  // copy name in temp to ch;
        this->name = ch;

        cout<<"Copy Constructor Called"<<endl;
        this->health = temp.health;  
        this->level = temp.level;
    }

// Print Function
    void print(){
        cout<<"[Name: "<<this->name<<", ";
        cout<<"Health: "<<this->health<<", ";
        cout<<"Level: "<<this->level<<" ]";
        cout<<endl<<endl;
    }

// Getters and Setters
    int getHealth(){ 
        return health;
    }

    char getLevel(){  
        return level;
    }

    void setHealth(int h){ 
        health = h;
    }

    void setLevel(char ch){
        level = ch;
    }

    void setName(char name[]){
        strcpy(this->name, name);  //Current pointer ko pehle wala name de diya
    }

// Destructor
    ~Hero(){
        cout<<"Destructor Called"<<endl;
    }

};

int main(){

    // Static
    Hero a;   // Iske liye destructor automatically call hota hai

    //Dynamic
    Hero *b = new Hero();  // Iske liye Manually destructor call karna padta hai;
    delete b;   // Manual Destructor Call
}