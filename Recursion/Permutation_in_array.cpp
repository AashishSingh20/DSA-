#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> arr, vector<vector<int>>& ans, int index){
    if(index >= arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int j=index;j<arr.size();j++){   // this loop will help in swapping with every element present in the array 
        swap(arr[index],arr[j]);  // swaps the index with jth element 
        solve(arr,ans,index+1);  // recursive call to solve for next index
        
        //backTrack
        swap(arr[index],arr[j]);  // Return jate time firse default case lado (Eg: abc=> abc and acb bana ab acb ko firse abc banado warna aage b ke combinations mein error hoga)
    }
}

int main(){

    int n,ele;
    cout<<"Enter number of elements in Array: ";
    cin>>n;
    vector<int> arr(n);

    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> ans;
    int index = 0;

    solve(arr,ans,index);

    cout<<"Permutations: ";
    for(int i=0;i<ans.size();i++){
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"],";
    }
}