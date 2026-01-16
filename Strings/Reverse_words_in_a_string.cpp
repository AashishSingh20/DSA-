// Reverses the whole sentence  (Eg:  it is raining  ->  ti si gniniar)
#include<iostream>
#include<vector>
using namespace std;

void reverseWord(vector<char>& s,int start, int end){  // It is used to reverse words 
    while(start<end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}


int main(){
    vector<char> s;
    string temp;
    cout<<"Enter a sentence: ";
    getline(cin,temp);

    for(int i=0;i<temp.length();i++){
        s.push_back(temp[i]);  
    }
    cout<<endl;

    int start = 0;

    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            int end = i-1;
            reverseWord(s, start, end);
            start = i + 1;
        }
    }

    cout<<"Reverse of sentence: ";
    for(int k=0;k<s.size();k++){
        cout<<s[k];
    }
    cout<<endl;
}




    // for(int k=0;k<s.size();k++){      // Eg: hello how are you ->  olleh woh era uoy
    //     cout<<s[k];
    // }

    //     for(int k=s.size();k>=0;k--){  // Eg: hello how are you -> you are how hello
    //     cout<<s[k];
    // }


    // just by twisting this loop we canget diffrenent output