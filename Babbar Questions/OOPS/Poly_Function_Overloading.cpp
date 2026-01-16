#include<iostream>
using namespace std;

class A{
    public:
        int a;
        int b;

    public:
        int add(){   
            return a+b;
        }

    void operator+ (A &obj){
/*        int value1 = this-> a;   // yeh 3 lines '+' wale operator ko call karne par value2-value1 kar deta hai
        int value2 = obj.a;
        cout<< "Output: " << value2-value1 << endl;  */
        
        cout<<"Hello Aashish"<<endl;  // Ab jitni baar '+' operator call hoga 'Hello Aashish' print hoga
    }

    void operator()  (){
        cout<<"Mein Bracket Hu."<<endl;   // ye bracket aane par yeh statement ko call kar dega
    }
};

int main(){
    A obj1, obj2;
    obj1.a = 2;
    obj2.a = 4;

    obj1 + obj2;
    obj1();
}