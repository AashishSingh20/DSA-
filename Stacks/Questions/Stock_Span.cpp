#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stockSpan(vector<int> arr){
    int n = arr.size();

    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty()  && arr[i] >= arr[st.top()]){   // Agar stack empty nahi hai and arr[i] par joh element hai woh top par joh index store hua hai us index ke element se bada hai then pop
            st.pop();
        }
        if(st.empty()){  // If stack is empty then ans mein curent index mein +1 karke push kardo
            ans[i] = i+1;
        }
        else{
            ans[i] = i - st.top();  // Else current index - index stored in the top of stack karke store in ans
        }
        st.push(i);    // Sab cjeck karne ke baad push index of curent element
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

    vector<int> ans = stockSpan(arr);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}