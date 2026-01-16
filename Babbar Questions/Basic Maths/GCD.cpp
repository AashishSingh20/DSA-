#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b){
    if(a==0){
        return b;
    }

    if(b==0){
        return a;
    }

    while(a != b){
        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

int main(){
    int num1,num2;
    cout<<"Enter Two Number: ";
    cin>>num1>>num2;

    int ans = gcd(num1,num2);
    cout<<"The GCD of "<<num1<<" and "<<num2<<" is: "<<ans<<endl;
}