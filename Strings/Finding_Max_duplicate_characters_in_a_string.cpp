#include<iostream>
using namespace std;

char MaxOccCharacter(string s){
    
    // Used to watch which alphabet has came how many times
    int temp[26] = {0};   // Used to keep how may times a character comes in the array
    for(int i=0;i<s.size();i++){
        char ch = s[i];   // ch mein string ke saare elements store honge
        int number = 0;   // it helps to increase the count if the element occurs more than one in a string
        number = ch - 'a';   // Suppose ch = 'o'  then 'o' - 'a' = 111 - 97 = 14 so it will increase count at 14 from 0 to 1
        temp[number]++;      // Here it is increasing the number 
    }

    // Used to find maximum number in the temp array
    int maxi = -1;  // Initially maxi is -1
    int ans = 0;  // Used to store maxi element's index which will be used to find the maximum occuring alphabet
    for(int j=0;j<26;j++){
        if(maxi < temp[j]){   // If element stored in maxi is less than temp then ...
            ans = j;          // Store index of j in ans
            maxi = temp[j];  // Update element in maxi 
        }
    }

    char finalAns =  'a' + ans;   // finalAns again converts index into alphabet
    return finalAns;    
}

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;

    char result = MaxOccCharacter(s);
    cout<<"Maximum occurring element in the string is: "<<result<<endl;
}