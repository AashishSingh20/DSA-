#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;

string firstNonRepeating(const string s){
    int n = s.size();
    string res = "";
    queue<int> q;

    map<char,int> count;   // Key-Value Pairs

    for(int i=0;i<n;i++){
        char ch = s[i];

        // Increase Count
        count[ch]++;

        // Push the Character in queue
        q.push(ch);

        while(!q.empty()){
            // For Repeating Character
            if(count[q.front()] > 1){  
                q.pop();
            }
            // For non Repeating Character
            else{
                res.push_back(q.front());  // Agar Non repeating hai toh usko res mein pus kardo and break from the while loop
                break;
            }
        }
        if(q.empty()){
            res.push_back('#');
        }
    }
    return res;
}

int main(){
    string s;
    cout<<"Enter a String: ";
    cin>>s;

    string ans = firstNonRepeating(s);
    cout<<"First Non Repaeting Characters in the String is: "<<ans<<endl;
}