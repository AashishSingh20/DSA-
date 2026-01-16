#include<iostream>
#include<vector>
using namespace std;

void subsequence(const string s, string output,int index, vector<string>& ans){
    if(index >= s.size()){
        ans.push_back(output);  // Tree ke last line par pohach gaye toh element ko store karalo fir return kardo
        return;
    }

    subsequence(s,output,index+1,ans);  // Excluding the element at index

    char element = s[index];  // Including the element at the index
    output.push_back(element);  // Element ko store karke output mein push kardega
    subsequence(s,output,index+1,ans); 
}

int main(){
    string str;
    cout<<"Enter String: ";
    cin>>str;

    vector<string> ans;
    string output = "";
    int index = 0;

    subsequence(str,output,index,ans);

    cout<<"Output: ";
    for(int i=0;i<ans.size();i++){
        cout<<"\""<<ans[i]<<"\",";   // \"  prints double inverted commas
    }
}