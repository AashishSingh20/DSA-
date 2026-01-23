#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevGreaterElement(vector<int> arr){
    int n = arr.size();

    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty()  && arr[i] >= st.top()){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;
    
    vector<int> arr;
    cout<<"Enter Array Elements: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    vector<int> ans = prevGreaterElement(arr);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}