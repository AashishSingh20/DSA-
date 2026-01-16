#include<iostream>
using namespace std;

bool checkPalindrome(string s, int i, int j){
    if(i>j){
        return 1;   // Base Condition
    }
    
    if(s[i]!=s[j]){  // If element at i is not equal to element at j then return false
        return 0;
    }
    
    return checkPalindrome(s,i+1,j-1);  // Recursive Call function increment i by 1 and decrement j by 1
}

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;

    int i = 0;
    int j = s.size()-1;

    if(checkPalindrome(s,i,j)){
        cout<<"It is a Palindrome";
    }
    else{
        cout<<"It is not a Palindrome";
    }
}