#include<iostream>
using namespace std;

int main(){
    int i= 5;
    {
        int i = 3;  // This is a local variable as it can be only accessed in this block 
        cout<<i<<endl;
    }
    cout<<i<<endl;  // This is Global as it can be accessed outside previous block

// Global Variable use mat karo uske jagah refrenced variable use karo
}