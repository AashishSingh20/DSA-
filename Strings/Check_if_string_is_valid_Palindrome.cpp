#include<iostream>
using namespace std;

// This checks if the string given is valid or invalid
bool valid(char ch){  
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9'){  
        return true;
    }
    cout<<"It is an Invalid String";  // If string has any special characters then it is invalid
    cout<<endl;
    return false;
    }

// This checks if alphabets are in lower case if not then it converts then into lower case
char toLower(char ch){  
    if(ch>='a' && ch<='z'){    
        return ch;
    }
    else{
        char temp = ch-'A'+'a';  // Here if ch is 'A' then  A-A+a = 'a' , if ch is 'C' then C-A+a = (67-65+97) = 99 -> 'c' 
        return temp;
    }
}

// This function checks if the string is a palindrome or not
bool checkPalindrome(string a){
    int s = 0;
    int e = a.length()-1;

    while(s<e){
        if(a[s] == a[e]){
            s++;
            e--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    string temp = "";   // Here temp is made to store all valid string characters

    for(int i=0;i<s.length();i++){  // Faltu Character hatadega
        if(valid(s[i])){   
            temp.push_back(s[i]);  // if valid then store in temp
        }
        else{
            break;
        }
    }

    for(int j=0;j<temp.length();j++){
        temp[j] = toLower(temp[j]);  // coneverts upper case into lower case
    }

    if(checkPalindrome(temp)){
        cout<<"It is a Palindrome";  // If all true then it is a Palindrome 
    }
    else{
        cout<<"It is not a Palindrome";  // If any false then it is not a Palindrome
    }
}