#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string> arr, int n){
    
    // Stores the final longest prefix
    string ans = "";
    
    // For traversing all characters of first string
    for(int i=0;i<arr[0].length();i++){
        char ch = arr[0][i];

        // boolean function to tell whether all characters in all string matches or not
        bool match = true;
    
        // For comparing character with remaining strings
        for(int j=1;j<n;j++){

            // Not match
            // if for the current i'th character index there are not characters in other string
            // or if ch is not eual to characters in arr mark false and break
            if(arr[j].size() < i  || ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(match == false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter number of strings in array: ";
    cin>>n;

    vector<string> arr;
    cout<<"Enter Strings in vector: ";
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }

    string ans = longestCommonPrefix(arr,n);
    cout<<"Longest Common Prefix is: "<<ans<<endl;
}