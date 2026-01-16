#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);   
    
    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            s.replace(i,1,"@40");   // Replaces element at i index with @40
        }
    }

    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
}