#include<iostream>
#include<vector>
using namespace std;

void solve(const string digits, string output, int index, vector<string>& ans, string mapping[]){

    if(index >= digits.size()){  // (Eg: digit = 23)
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';  // This gives the value (Eg: Digit is 2 in first iteration index is 0 so digits[0] = 57 and 57-55 = 2 which is in int)
    string value = mapping[number];  // It gives what is mapped at the number (Eg: Here 2 is mapped with abc)

    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);  // pushes value (Eg: in 1st iteration value is 2 so value[0] = a, value[1] = b, value[c] = c)
        solve(digits,output,index+1,ans,mapping);   // Ab yeh sare previous operations 3 par honge acc to example
        output.pop_back();   // Used for backtracking // (Eg: a ke sare combinations ho gaye ab khali karo a taki b ke combinations ho paye)
    }
}

int main(){
    string digits;
    cout<<"Enter Number string: ";
    cin>>digits;

    vector<string> ans;
    string output;

    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solve(digits,output,index,ans,mapping);

    cout<<"Total Combinations: ";
    for(int i=0;i<ans.size();i++){
        cout<<"\""<<ans[i]<<"\",";
    }
}