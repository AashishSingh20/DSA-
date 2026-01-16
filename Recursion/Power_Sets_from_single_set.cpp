#include<iostream>
#include<vector>
using namespace std;

void solve(const vector<int>arr, vector <int> output, int index, vector<vector<int>>& ans){  // const vector<int>arr shows that arr will not be modified
    
    // Base Case
    if(index >= arr.size()){  // when index reaches the size of array then push all output subset to ans
        ans.push_back(output);
        return;
    }

    //Exclude 
    solve(arr,output,index+1,ans);  // Yeh line yeh batata hai ki hum current index ko exclude kar rahe hai
    
    // include
    int element = arr[index];  // It is used to store the current element
    output.push_back(element);  // current element ko output subset me add kar rahe hai
    solve(arr,output,index+1,ans);  // next index pe jaa rahe hai
}

int main(){

    int n;
    cout<<"Enter Array Size: ";
    cin>>n;
    vector<int> arr(n); 

    cout<<"Enter Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> ans;  // It is used to store all the subsets
    vector<int> output;  // It is used to store one subset at a time

    int index = 0;  // It is used to track the current index in the array
    solve(arr,output,index,ans);   // Function Call
    
    cout<<"Output: ";
    for(int i=0;i<ans.size();i++){   
        cout<<"{ ";
        for(int j=0;j<ans[i].size();j++){  // ans[i] is one subset
            cout<<ans[i][j]<<" ";
        }
        cout<<"},";
    }
}