#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    string part;
    cout<<"Enter part you want to delete: ";
    cin>>part;

    while(s.length() != 0 && s.find(part) < s.length()){  // Yeh tabhi chalana jab tak string s ka length 0 na ho jaye and part length se chota ho
        s.erase(s.find(part), part.length());   // If part is found in s then erase it
    }
    
    cout<<" Now the string is: ";
    int i=0;
    while(i<s.size()){
        cout<<s[i++];
    }
}