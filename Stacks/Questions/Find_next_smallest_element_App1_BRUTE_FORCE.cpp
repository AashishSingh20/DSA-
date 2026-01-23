#include<iostream>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[i]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans; 
}

int main(){
    int n;
    cout<<"Enter the number of Elements in the Array: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter Array Elements: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    vector<int> ans = nextSmallerElement(arr);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}