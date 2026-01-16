#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};
    char ch[10] = "abcdefghi";

    cout<<"Address of First Block: "<<arr<<endl;
    cout<<"Whole character Array: "<<ch<<endl; 

    char *c = &ch[0];
    cout<<c<<endl;  // Prints entire String  (pointer 'c' ke andar value ch[0] se li hai isliye full print hoga ch[1] dalte toh 'b' se start hota)

    cout<<*c<<endl; // This Prints character value at at which c is pointing here it is pointing towards ch[0]

    
    char temp = 'z';
    char *p = &temp;
    cout<<p<<endl;  // 'z' print karne ke baad randomly kuch bhi print karega until it reaches NULL Pointer

    
}