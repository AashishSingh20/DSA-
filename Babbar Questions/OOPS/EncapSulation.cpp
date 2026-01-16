#include<iostream>
using namespace std;

class Student{
    private:
        string Name;
        int age;
        int height;

    public:
    int getAge(){
        return this->age;
    }
};

int main(){
    Student first;
    cout<<"Sab Sahi Chal Raha Hai."<<endl;
}