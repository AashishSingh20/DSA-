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
        TrieNode* child;   // Stores Next Node

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

    bool searchUtil(TrieNode* root, string &word, int i){
        // Base Case
        // Jitna word search karna hai woh mil chuka hai
        // check ki jaha word khatam hua hai woh terminal node hai ki nahi and return accordingly
        if(i == word.length()){
            return root->isTerminal;
        }

        // converts all alphabets to lower then checks
        int index = tolower(word[i]) - 'a';
        TrieNode* child;

        // If first word is present in Trie aage badho
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        // If character is absent from Trie
        else{
            return false;
        }

        // Recursion
        return searchUtil(root->children[index],word,i+1);
    }

    bool searchWord(string word){
        return searchUtil(root,word,0);
    }

    // Checks ki word to be deleted has child or not
    // If child exists we just put isTerminal as False
    // If no child node exists we completely delete the whole word from tree
    bool hasChildren(TrieNode* node){
    for(int i = 0; i < 26; i++){
        if(node->children[i] != NULL)
            return true;
    }
    return false;
    }

    bool deleteUtil(TrieNode* root, string &word, int i){
        if(i == word.length()){

            // word not present in Trie
            if(!root->isTerminal){
                return false;
            }

            // Unmark Word
            root->isTerminal = false;

            // Delete node only if no children exists
            return !hasChildren(root);
        }

        int index = tolower(word[i]) - 'a';
        TrieNode* child;
        
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return;
        }

        return deleteUtil(root->children[index],word,i+1);
    }

    void deleteWord(string word){
        deleteUtil(root,word,0);
    }

};

int main(){

    Trie *t = new Trie();
    
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout<<"Present or Not"<<": "<<t->searchWord("ARM")<<endl;
}