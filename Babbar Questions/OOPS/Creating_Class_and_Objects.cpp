#include<iostream>
using namespace std;

class Hero{  // Here Hero is the class
    private:  // Sirf class ke andar access ho payega bahar access kiya toh error dikhaega
        char type;

    public:   // Class ke andar aur bahar sare data members access honge
        int health;  // health is a property of class
        char level;
    

// Getters and Setters   (Used to Access private data members outside class)
    int getHealth(){   // Getters and setters should be public
        return health;
    }

    char getType(){   // Fetch data member
        return type;
    }

    void setHealth(int h){   // Conditions dena
        health = h;
    }

    void setType(char t){
        type = t;
    }

};

int main(){
    Hero Aashish;  // Creation of class h1
    // cout<<"Size: "<<sizeof(Aashish)<<endl;  // Gives size of the object Aashish  // Gives total size of all datatype in Hero class(if 'char' it appoints 4 byte due to padding and greedy alignment)

    Aashish.health = 210;
    Aashish.level = 'S';

    cout<<"Health is: "<<Aashish.health<<endl;
    cout<<"Level is: "<<Aashish.level<<endl;  
    // cout<<"Type is: "<<Aashish.type<<endl;  // Error

    cout<<"Type is: "<<Aashish.getType()<<endl;  // gets the type
}
