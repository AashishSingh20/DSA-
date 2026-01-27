#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> firstNegInt(const vector<int> arr, int k){
    int n = arr.size();
    deque<int> dq;
    vector<int> ans;

    //Step 1:- Process 1st Window of k Size
    for(int i=0;i<k;i++){
        if(arr[i] < 0){   // Agar window mein element mila joh negative hai toh store it's index in deque
            dq.push_back(i);
        }
    }

    //Step 2:-  Store ans of first k size window
    if(!dq.empty()){   // Agar dq ka is greater than 1 means 1st window mein se koi toh index deque mein gaya hai so 
        ans.push_back(arr[dq.front()]);  // deque ke front mein joh index store hai us index par jaake arr mein se value ko ans mein store kardo
    }
    else{
        ans.push_back(0);  // Else if deque is empty matlab negative element nahi hai us window main toh ans mein 0 daldo
    }

    //Step 3:-  Process for remaining windows
    for(int i=k;i<n;i++){
        //Step 1:- Removal of 1st element of the previous window
        if(!dq.empty() && i - dq.front() >= k) // i - dq.front() yeh check karega ki joh deque ke front mein padi hai woh current k size window mein aati hai ki nahi aati hai toh rehne do warna pop kardo
            dq.pop_front();  // pehle wale element in window ko pop kardo

        //Step 2:- Addition of new element in window
        if(arr[i] < 0){   // agar new element is less than 0 then
            dq.push_back(i);  // push the index of the negative element in the deque
        }

        //Step 3:- Store ans for the current window
        if(dq.size() > 0){   // Agar deque ka size baccha hai then 
            ans.push_back(arr[dq.front()]);   // deque ke front mein joh index store hai us index par jaake arr mein se value ko ans mein store kardo
        }
        else{
            ans.push_back(0);   // Else if deque is empty matlab negative element nahi hai us window main toh ans mein 0 daldo
        }
    }  
    return ans; 
}

int main(){
    int n;
    cout<<"Enter Number of Elements the Array: ";
    cin>>n;

    cout<<"Enter Array Elements: ";
    vector<int> arr;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    int k;
    cout<<"Enter Window Size: ";
    cin>>k;

    if(k > n || k < 1){
        cout<<"Enter valid value fo k !";
        return 0;
    }

    vector<int> ans = firstNegInt(arr,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}