#include<iostream>
using namespace std;

// void print(int *p){
//     cout<<p<<endl; // Prints address of value

//     cout<<*p<<endl; // Prints value in p pointer which is storing address of value(So it prints value)
// }

// void update(int *p){
//     // p = p+1;
//     // cout<<"Updated: "<<p<<endl;  // Ab p ki updated value print hogi

//     *p = *p+1;  // Ab hamne value apdate kar diya hai
// }

int getSum(int arr[], int n){

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int value = 4;
    int *p = &value;
    // print(p);


    // cout<<"Before: "<<p<<endl;
    // update(p);
    // cout<<"After: "<<p<<endl;  // Yeh alag p hai aur function mein alag p hai isliye same address print hoga
    // cout<<endl;


    // cout<<"Before: "<<*p<<endl;
    // update(p);
    // cout<<"After: "<<*p<<endl;  // Yaha value stored hai toh update mein value update hone par yaha bhi dikhega(Value Update kar sakte hai main function mein print karke but address nahi)


    int arr[5] = {1,2,3,4,5};
    cout<<"Sum is: "<<getSum(arr,5)<<endl;  // Waha agar mein 5 ki jagah sizeof(arr) dalunga toh yeh arr ka size na consider karke kuch garbage value consider karrega kyuki yaha function mein int arr[] is same as int *arr(Function is passing array as a pointer)
    cout<<sizeof(arr)<<endl;
}