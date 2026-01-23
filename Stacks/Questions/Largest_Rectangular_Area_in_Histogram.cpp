#include<iostream>
#include<climits>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerIndexes(vector<int> arr, int n){
    vector<int> ans(n);
    stack<int> st;

    st.push(-1);
    for(int i=n-1;i>=0;i--){
        while(st.top() != -1 && arr[i] <= arr[st.top()]){  // agar arr[i] is small than element at the index of top and if top is not equal to -1 then pop
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerIndexes(vector<int> arr, int n){
    vector<int> ans(n);
    stack<int> st;

    st.push(-1);
    for(int i=0;i<n;i++){
        while(st.top() != -1 && arr[i] <= arr[st.top()]){  // agar arr[i] is small than element at the index of top and if top is not equal to -1 then pop
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> heights){
    int n = heights.size();

    vector<int> next(n);  // Next smaller Elements ke Indexes ko store Karega
    next = nextSmallerIndexes(heights,n);

    vector<int> prev(n);   // previous Smaller Elements ke Indexes ko store Karega
    prev = prevSmallerIndexes(heights,n);

    int area = INT_MIN;
    for(int i=0;i<n;i++){
        int l = heights[i];    // Length = height of the blocks
        if(next[i] == -1){   // Agar next[i] -1 hua toh area negative ho jayega so yeh check lagalo
            next[i] = n;     // Agar aisa ho jaye toh next[i] mein size of arr ki value daldo
        }
        int b = next[i] - prev[i] - 1;    // Breadth = nextSmallerElement index - previousSmallerElement index - 1
        int newArea = l*b;   // new area nikalo with new length and breadth
        area = max(area,newArea);   // Max Area ko nikalo compare it with old area if newArea is greater than old Area update area
    }
    return area;
}

int main(){
    int n;
    cout<<"Enter Number of Blocks in Histogram: ";
    cin>>n;

    vector<int> heights;
    cout<<"Enter Height of Individual Blocks: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        heights.push_back(data);
    }

    int ans = largestRectangleArea(heights);
    cout<<"Largest Area of Histogram: "<<ans<<endl;
}