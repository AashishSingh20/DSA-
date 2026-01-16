// This also reverses whole sentence (Eg:- hello how are you  -> ypu are how hello)

#include<iostream>
#include<vector>
using namespace std;

void reverseWord(vector<char>& s,int start, int end){  // It is used to reverse 
    while(start<end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}


int main(){
    vector<char> s;   // It is the main string
    string temp;   // As vector<char> cannot take inputs in sentence form directly so we use temp
    cout<<"Enter a sentence: ";
    getline(cin,temp);   // This helps us to take input in a string

    for(int i=0;i<temp.length();i++){
        s.push_back(temp[i]);     // It pushes all elements we take from temp into s
    }
    cout<<endl;

    int n = s.size();
    reverseWord(s,0,n-1);
    
    int start = 0;
    for (int i=0; i<=n; i++) {
        if (i == s.size() || s[i] == ' ') {   // If i reaches the end of string or if there comes a space then this condition will work
            int end = i-1;   //  End is the last element of the word
            reverseWord(s, start, end);  // Reverses only the word who is between start and end
            start = i + 1;   // update start to point to the next word if any
        }
    }

    cout<<"Reverse of sentence: ";
    for(int k=0;k<n;k++){   // Just prints the sentence 
        cout<<s[k];
    }
    cout<<endl;
}