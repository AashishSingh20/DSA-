#include<iostream>
using namespace std;

void sayNum(int n, string arr[]){
    if(n==0){
        return;
    }

    int digit = n%10;  // This gets us the last number (Eg:- 122  122%10 == 2)
    n = n/10;  // This will remove the last number (Eg: In 122 after 1 call 122/10 = 12 then after 2nd call 12/10 = 1)

    sayNum(n,arr);
    cout<<arr[digit]<<" ";  // It gets the string at the digit(Eg: in 122 first it will get arr[2] which is Two)
}

int main(){
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    sayNum(n,arr);
}