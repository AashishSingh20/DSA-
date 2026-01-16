#include<iostream>
using namespace std;

string reverseStr(string& s, int i, int j){     //METHOD 1(using 2 pointers)
    if(i>j){  // Base Case
        return s;
    }

    swap(s[i],s[j]);  // Swap karo i and j wale elements ko
    i++;
    j--;

    reverseStr(s,i,j);  // Recursive call
}


string reverseStr2(string& s, int i, int n){     // METHOD 2(using single Pointer)
    if(i>=n/2){  // Base Case(bas middle tak chalega agar uske aage gaya toh out of bounds ho jayega)
        return s;
    }

    swap(s[i],s[n-i-1]);  // Swap karo i and n-i-1 ko swap karo(eg: i=0,n=4 then swap s[0],s[4-0-1] then s[1],[4-1-1] and so on)

    return reverseStr(s,i+1,n);  // Recursive call (Increment value of i with each call)
}


int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    
    int n = s.size();

    int i = 0;
    int j = n-1;

    reverseStr(s,i,j);
    cout<<s<<endl;
}