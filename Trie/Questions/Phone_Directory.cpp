#include<iostream>
#include<vector>
using namespace std;
#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;  // Used to store Character of a node
        TrieNode* children[26];  // Each node can have 26 possible children as there are 26 alphabets
        bool isTerminal;   // Marks end of a valid word

        // Constructor  
        TrieNode(char ch){
            data = ch;  // Stores character
            for(int i=0;i<26;i++){   // Intitialize children (Initially no children exists)
                children[i] = NULL;
            }
            isTerminal = false; // Terminal is marked false as initially no word is completed
        }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        // Initialize root of Trie with \0(dummy character)
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string &word, int i){
        // Base Case
        // Agar i word ke length ke barabar ho gaya hai means word is fully traversed 
        // And Last character ko terminal mark kar diya hai
        if(i == word.length()){
            root->isTerminal = true;
            return ;
        }

        int index = tolower(word[i]) - 'a';
        TrieNode* child;   // points to the Next Node

        // If Character is Present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        // If Character is Absent
        else{
            child = new TrieNode(word[i]);
            root->children[index] = child;
        }

        // Recursion Call
        insertUtil(child, word,i+1);
    }

    void insertWord(string word){
        insertUtil(root,word,0);
    }

    void printSuggestions(TrieNode*curr, vector<string> &temp, string prefix){
        // agar curr Node Terminal Node hai toh prefix ko temp mein push kardo
        if(curr->isTerminal){
            temp.push_back(prefix); 
        }
    
        for(char ch = 'a'; ch <= 'z'; ch++){
            TrieNode* next = curr->children[ch-'a'];
    
            // next NULL nahi hai matlab child exists toh usko prefix mein daldo
            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }  
        }
    }
    
    vector<vector<string>> getSuggestions(string s){
        
        TrieNode* prev = root;  // Points to the curr element
        vector<vector<string>> output;  // Stores the output of strings
        string prefix = "";  // Tells us the current string character
    
        for(int i=0;i<s.length();i++){
            char last = s[i];  // this points to the last character of the string s which we have to find
    
            prefix.push_back(last);  // string ke curr element ko prefix mein push kar denge 
    
            // Check for last character
            TrieNode* curr = prev->children[last - 'a'];
    
            // If not found push 0 in the output;
            if(curr == NULL){
                while(i < s.length()){
                    output.push_back({"0"});
                    i++;
                }
                break;
            }
    
            // if character is found
            vector<string> temp;
            printSuggestions(curr,temp,prefix);
    
            output.push_back(temp);
            prev = curr;
        }
    
        return output;
    } 
};


vector<vector<string>> displayContacts(vector<string> &contactList, int n, string s){

    // Creation of Trie
    Trie *t = new Trie();

    // Insert all contact in trie
    for(int i=0;i<contactList.size();i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    // return ans
    return t->getSuggestions(s);
}

int main(){
    int n;
    cout<<"Enter Directory Size: ";
    cin>>n;

    vector<string> contact;
    cout<<"Enter Contacts: ";
    for(int i=0;i<n;i++){
        string data;
        cin>>data;
        contact.push_back(data);
    }

    string s;
    cout<<"Enter contact to search: ";
    cin>>s;

    // 3
    // geekistest geeksforgeeks geeksfortest
    // geeips
    vector<vector<string>> ans = displayContacts(contact,n,s);
    cout<<"After searching the contact the output is: "<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    } 
}