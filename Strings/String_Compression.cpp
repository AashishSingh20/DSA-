#include<iostream>
using namespace std;

int compress(string &s){
    int i = 0;  // Kisi bhi element ke first occurrence point karne mein use hoga
    int ansIndex = 0;  // Yeh index store mein madat karega
    int n = s.size();

    while(i<n){   // Jabtak i string ke size tak nahi pohach jata tak tak yeh loop chalega
        int j = i+1;  // Ye last occurrece of any element ko track karne ke liye use hoga
        while(j<n && s[i] == s[j]){  // This loop is for j. jabtak j string size se kam hai and jabtak element at i is same as element at j yeh loop chalega
            j++;
        }

        // Next step tab hoga jab string pura traverse karliya yah toh naya character mil gaya
        s[ansIndex++] = s[i];   // old character ko store kar liya and next index par chal gaya

        int count = j-i; // It tells how many times a character has come in our string

        if(count>1){
            string cnt = to_string(count);  // This converts integer into string so 12 becomes-> "1","2" which we want if count is greater than single digit

            for(int i=0;i<cnt.size();i++){  // loop chalega to store all characters in the string cnt
                char ch = cnt[i];  // char ch banao aur cnt ke saare elements lo usmein daalo
                s[ansIndex++] = ch;   // abhi joh ch mein daala hai usse string s mein daldo and index ko increment kardo
            }
        }

        i=j;  // Ab i ko j ki jagah par daldo taki baki characters ko bhi compress kar paye
    }
    return ansIndex;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    int newLength = compress(s);
    cout<<"The compressed string: ";
    for(int i=0;i<newLength;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;

}    