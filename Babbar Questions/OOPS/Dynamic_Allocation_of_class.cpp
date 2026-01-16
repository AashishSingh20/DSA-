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

};

int main(){
    Hero a;  // Static Allocation of object
    a.setHealth('70');
    a.setType('Flame');
    cout<<"Health is: "<<a.health<<endl;
    cout<<"Level is: "<<a.level<<endl;
    
    Hero *b = new Hero;   // Dynamic Allocation of object
    b->setHealth('100');
    b->setType('Water');

    cout<<"Health is: "<<(*b).health<<endl;
    cout<<"Level is: "<<(*b).level<<endl;
    cout<<"Type is: "<<(*b).getType()<<endl;
    
                //OR
    cout<<"Health is: "<<b->health<<endl;
    cout<<"Level is: "<<b->level<<endl;
    cout<<"Type is: "<<b->getType()<<endl;
    
}