#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int> arr){
    int n = arr.size();

    stack<int> st;
    vector<int> ans(n);

    st.push(-1);
    for(int i=0;i<n;i++){
        while(arr[i] <= st.top()){
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

    vector<int> ans = prevSmallerElement(arr);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}