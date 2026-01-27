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
        while(st.top() != -1 && arr[i] <= arr[st.top()]){ 
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
        while(st.top() != -1 && arr[i] <= arr[st.top()]){ 
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestAreaHistogram(vector<int> heights, int n){

    vector<int> next(n);  
    next = nextSmallerIndexes(heights,n);

    vector<int> prev(n);   
    prev = prevSmallerIndexes(heights,n);

    int area = INT_MIN;
    for(int i=0;i<n;i++){
        int l = heights[i];   
        if(next[i] == -1){  
            next[i] = n;    
        }
        int b = next[i] - prev[i] - 1;  
        int newArea = l*b;   
        area = max(area,newArea);  
    }
    return area;
}

int maxAreaRectangle(vector<vector<int>> &mat, int n){

    // Step 1:- Compute Area for 1st Row
    int area = largestAreaHistogram(mat[0],n);  // Removes MaxArea of 1st Row 

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){

            // Row Update: By adding previous row's value
            if(mat[i][j] != 0){
                mat[i][j] = mat[i][j] + mat[i-1][j];  // Gives new values by adding previous and current row
            }
            else{
                mat[i][j] = 0;   // If the current row has 0 value in any row then that row will be considered as 0 not values from the previous row will not be added to it
            }
        }

        // Entire row is Updated Now now calculate area 
        int newArea = largestAreaHistogram(mat[i],n);
        area = max(area, newArea);  // Checks max area between new area and previous area
    }
    return area;    // It returns the max area
}

int main(){
    int n;
    cout<<"Enter Number of rows in the Matrix: ";
    cin>>n;

    if(n == 0){
        cout<<"Invalid Size of Matrix!";
        return 0;
    }

    vector<vector<int>> mat(n, vector<int> (n));
    cout<<"Enter Number in Binary: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    cout<<"Array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    int max = maxAreaRectangle(mat,n);
    cout<<"Max Area of Rectangle in Binary Matrix is: "<<max<<endl;
}