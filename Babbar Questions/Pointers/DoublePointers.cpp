#include<iostream>
using namespace std;

void update(int **p2){
     p2 = p2 + 1;
    // Kya Isse kuch hoga?? -> NO(Pass by value se aaya hai)

     *p2 = *p2 + 1;
    // Kya Isse kuch Hoga?  -> YES(p ki value change ho jayegi kyuki '*p2'  'p' ko point kar raha hai)

    **p2 = **p2 + 1;
    // Kya isse kuch hoga?  -> YES( i ki value change ho jayegi kyuki '**p2'  'i' ko point kar raha hai)
}

int main(){
    int i = 5;
    int *p = &i;
    int **p2 = &p;

    cout<<"Printing p: "<<p<<endl;
    cout<<"Address of p: "<<&p<<endl;
    
    cout<<" "<<*p2<<endl;  // Prints value of p as it is a pointer of p
    cout<<" "<<p2<<endl;   // prints Address of p and it also value at p2
    cout<<" "<<&p2<<endl;  // Prints Address of p2

    //How to Print value at i
    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;

    //How to Print Address of i
    cout<<" "<<&i<<endl;
    cout<<" "<<p<<endl;
    cout<<" "<<*p2<<endl;

    //How to Print value in p
    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl; 

    //How to Print Address of p
    cout<<" "<<&p<<endl;
    cout<<" "<<p2<<endl;

    cout<<"Before: "<<i<<endl;
    cout<<"Before: "<<p<<endl;
    cout<<"Before: "<<p2<<endl;
    update(p2);
    cout<<"After: "<<i<<endl;
    cout<<"After: "<<p<<endl;
    cout<<"After: "<<p2<<endl;  


}