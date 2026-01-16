#include<iostream>
using namespace std;

int main(){
    int arr[10] = {0,2,5,10,15};
    cout<<"Address of First Memory Block: "<<arr<<endl;
    cout<<"Address of Second Memory Block: "<<arr+1<<endl;

    cout<<"Address of First Memory Block: "<<&arr[0]<<endl;
    cout<<"Address of Second Memory Block: "<<&arr[0]+1<<endl;

    cout<<"Value at First Memory Block: "<<*arr<<endl;  
    cout<<"Value at First Memory Block + 1: "<<*arr+1<<endl; 
    cout<<"Value at Second Memory Block: "<<*(arr+1)<<endl; 

    int i = 3;
    cout<<"Value at 3rd Index in Array: "<<i[arr]<<endl;
    cout<<"Value at 3rd Index in Array: "<<arr[i]<<endl;
    cout<<endl;
    
    
    int temp[10];
    int *ptr = &temp[0];
    cout<<"Size of Array: "<<sizeof(temp)<<endl;
    cout<<"Size of Pointer: "<<sizeof(ptr)<<endl;
    cout<<"Size of Pointer: "<<sizeof(*ptr)<<endl;  // Gives size of element to which ptr is pointing towards which here is integer so it gives output as 4
    cout<<endl;
    

    int a[20] = {1,3,5,7};
    cout<<&a[0]<<endl;  // All three gives same output address of 1st block
    cout<<&a<<endl;
    cout<<a<<endl;

    int *p = &a[0];
    cout<<p<<endl;  // gives Address of 1st Block
    cout<<*p<<endl; // Gives value at 1st Block
    cout<<&p<<endl;  // Gives Address of p pointer
    cout<<endl;


    int arr[10] = {1,3,5,7,9};
    int *ptr = &arr[0]; 
    cout<<ptr<<endl;  // Gives Address of 1st block

    ptr = ptr+1;
    cout<<ptr<<endl;  // Gives Address of 2nd Block
    cout<<endl;

}