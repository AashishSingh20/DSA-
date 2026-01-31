#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int solve(const vector<int> arr, int n, int k){

    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of First k size Window
    for(int i=0;i<k;i++){
        
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){   // maxi deque ko pop karte raho from back jabtak uske back wale index mein koi aisa element na aa jaye joh arr wale element se bada ho
            maxi.pop_back();
        } 

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];  // Store ans from first window

    // Process Remaining Windows
    for(int i=k;i<n;i++){

        // Move to next Window 

        // Step 1: Removal
        while(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >= k){
            mini.pop_front();
        }

        // Step 2: Addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){   
            maxi.pop_back();
        } 

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        
        ans += arr[maxi.front()] + arr[mini.front()];  // Firse ans mein baki process kiye hua answers put sum kardo
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter number of elements in the Array: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    int k;
    cout<<"Enter window Size: ";
    cin>>k;

    int ans = solve(arr,n,k);
    cout<<"The Sum of Max and Min Elements of all subarrays of size k is: "<<ans;
}