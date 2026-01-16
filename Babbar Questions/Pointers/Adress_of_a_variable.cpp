#include<iostream>
using namespace std;

int main(){
    int n = 5;
    cout<<"Number: "<<n<<endl;
    cout<<"Adress of number n: "<<&n<<endl; // Here & n is the address of n

    int *ptr = &n;  // 'n' is int so 'ptr' will also be int
    cout<<"Value: "<<*ptr<<endl;
    cout<<"Address: "<<ptr<<endl;

    double d = 2.2;  
    double *p2 = &d;  // Pointer will be of same datatype as it's variable

    cout<<"Value: "<<*p2<<endl;  // Points to the value
    cout<<"Address: "<<p2<<endl;  // Points to the address to the value

    cout<<"Size of Integer: "<<sizeof(n)<<endl;  // Size of Integer is 4
    cout<<"Size of Pointer: "<<sizeof(ptr)<<endl;  // Size of pointer is 8 but in 32 bit systems it is 4

    cout<<"Size of Double: "<<sizeof(d)<<endl;  // Size of Double is 8
    cout<<"Size of Pointer: "<<sizeof(p2)<<endl;  // Size of pointer is 8 but in 32 bit systems it is 4

}