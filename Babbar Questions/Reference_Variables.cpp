#include<iostream>
using namespace std;

// int& func(int n){     // This is a Bad Practice  (Here 'num' and 'ans' are local variables)    
//     int num = n;    // There is a possibility that we won't be able to access 'ans' and 'num'
//     int& ans = num;
//     return ans;
// }

void update1(int n){   //Pass by value
    n++;
}

void update2(int& n){  // Pass by reference
    n++;
}

int main(){
    int i = 5;
    int &j = i;    // Creates Reference Variable 'j'

    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<i<<endl;
    
    int a = 5;
    cout<<"Before: "<<a<<endl;
    update1(a);  // Will give no change in output as pass by value parameter
    cout<<"After: "<<a<<endl;

    update2(a);  // This will create a change as 'n' is passed as a reference of 'a', so any changes in 'n' will affect 'a'
    cout<<"After: "<<a<<endl;
}