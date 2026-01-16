#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int>& ans){
    int i = 0;
    int j = ans.size()-1;
    
    while(i<j){
        swap(ans[i],ans[j]);
        i++;
        j--;
    }
    return ans;
}

vector<int> arraySum(vector<int>& arr1, int m, vector<int>& arr2, int n){
    int i = m-1;   // Sum of all elements always start from last, here i is at last position of array 1
    int j = n-1;   // Here j is at last position of array 2
    int carry = 0;  // Keeps record of all carry used in the code
    vector<int> ans;

    while(i>=0 && j>=0){  // If elements are in both array 1 and array 2
        int sum =  arr1[i] + arr2[j] + carry;  // Sum of elements from last of both elements
        carry = sum/10;   // suppose if last element is 9 and 9 so 8 will be there and 1 is carry which can be found by 9+9 = 18 and 18/10 = 1(round figure in int)
        int value = sum%10;  // Value is the value that will stay at that place here in 18 8 stays and 1 goes in carry as 9+9=18 and 18%10 = 8
        ans.push_back(value);  //This inserts the value into the ans array
        i--;
        j--;
    }
    
    // First array is greater than the second array
    while(i>=0){
        int sum =  arr1[i] + carry;   // Here there is no array 2 left so sum is only array 1 and carry if any
        carry = sum/10;   
        int value = sum%10;
        ans.push_back(value);
        i--;   
    }

    // Second Array is greater than the first Array
    while(j>=0){
        int sum =  arr2[j] + carry;  // Here there is no array 1 so sum is only array 2 and carry if any
        carry = sum/10;
        int value = sum%10;
        ans.push_back(value);
        j--;
    }
    
    // After summation of both array carry is left
    while(carry != 0){
        int sum = carry;
        carry = sum/10;
        int value = sum%10;
        ans.push_back(value);
    }
    return reverse(ans);   // The values we are putting in the ans array is in reverse so to correct it we use reverse function
}

int main(){
    int m,n,ele;

    cout<<"Enter length of Array 1: ";
    cin>>m;
    cout<<"Enter length of Array 2: ";
    cin>>n;

    vector<int> arr1;
    cout<<"Enter Elements of Array 1: ";
    for(int i=0;i<m;i++){
        cin>>ele;
        arr1.push_back(ele);
    }

    vector<int> arr2;
    cout<<"Enter Elements of Array 2: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr2.push_back(ele);
    }
    
    vector<int> result = arraySum(arr1,m,arr2,n);
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}