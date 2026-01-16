#include<iostream>
#include<string>
using namespace std;

string eraseAdjDuplicate(string s){
    int i = 0;
    while(i<s.size()-1){   // Loop will go untill whole string has been traversed
        if(s[i] == s[i+1]){   // If element at i is same as element at i+1 then erase elements 
            s.erase(i,2);  
            if(i>0){    // after erasing if i is at index more than 0 then decrement i by 1
                i--;
            }
        }
        else{
            i++;  // if no duplicats just increment i 
        }
    }
    return s;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    string ans = eraseAdjDuplicate(s);   //Store output from function into ans
    cout<<"After removing all Adjacent Duplicates: "<<ans<<endl;
}