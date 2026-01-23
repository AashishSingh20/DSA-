#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    st.push(-1);
    for(int i=n-1;i>=0;i--){
        while(st.top() >= arr[i]){
            st.pop();
        }
        ans[i] = st.top();
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

    vector<int> ans = nextSmallerElement(arr);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}