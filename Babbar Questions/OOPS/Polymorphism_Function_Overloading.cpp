#include<iostream>
using namespace std;

class A{
    public:
        void sayHello(){
            cout<<"Hello Aashish."<<endl;
        }

        // void sayHello(){     // Same naam hai iska aur upar wale ka toh error aayega
        //     cout<<"Hello Aashish."<<endl;
        // }

        void sayHello(string name){   // Ab chal jayega(Function name same but function signature is different)(Funcion Overloading)
            cout<<"Hello"<<name<<endl;
        }
        
        // int sayHello(string name){   //Only change in return type Not a overloading 
        //     cout<<"Hello"<<name<<endl;
        // }
        
};

int main(){
    A obj;
    obj.sayHello();
}