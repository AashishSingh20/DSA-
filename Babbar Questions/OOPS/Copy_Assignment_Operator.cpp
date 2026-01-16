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

};

int main(){
    Hero hero1;
    hero1.setHealth(80);  // hero 1 ka health set ho gaya
    hero1.setLevel('S');  // Hero 1 ka level set ho gaya
    char name[8] = "Aashish";  // name hamne ek char banaya
    hero1.setName(name);  // wohi char name hamne name set kar diya

    Hero hero2(hero1);  // Calls Default copy constructor after we comment the copy constructor we wrote in class


    hero1.name[0] = 'G';
    hero1.level = 'A';
    hero1.print();
    hero2.print();
    
    hero1 = hero2;  // Copy Assignment Operator (hero 2 ki values ko hero 1 mein daal dega)

    hero1.print();
    hero2.print();
}