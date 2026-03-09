#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    // Template for unordered Map   
    // Stores Values in Key Value Pair
    // Creation
    unordered_map<string,int> mp;

// Insertion
    // Method 1
    pair<string,int> pair1 = {"babbar",3};
    mp.insert(pair1);
    
    // Method 2
    pair<string,int> pair2("love",2);
    mp.insert(pair2);

    // Method 3
    mp["mera"] = 1;
    // Will update mera 
    mp["mera"] = 2;

// Search
    cout<<mp["mera"]<<endl; 
    cout<<mp.at("babbar")<<endl;

    // Shows out of range
    // cout<<mp.at("unkownkey")<<endl;

    // Unknownkey ke liye entry ban jayegi map mein 0 key ke sath
    cout<<mp["unkownkey"]<<endl;

// Size
    cout<<"Map Size: "<<mp.size()<<endl;

// To check key presence(String map mein presnt hai ki nahi)
    cout<<mp.count("bro")<<endl;  // If present return 1 and if absent returns 0

// Erase
    mp.erase("love");
    cout<<"After Erase, Map Size: "<<mp.size()<<endl;

// Traverse whole map using loop
    for(auto i : mp){
        cout<<i.first<<" "<<i.second<<" ";
    }
    cout<<endl;

    // Using iterators
    unordered_map<string,int> :: iterator it = mp.begin();

    while(it != mp.end()){
        cout<<it->first<<" "<<it->second<<" ";
        it++;
    }
    cout<<endl;
}