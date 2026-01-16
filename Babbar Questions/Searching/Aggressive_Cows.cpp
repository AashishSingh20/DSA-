#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int k, int n, int mid){
    long long cowCount = 1;
    long long lastPosition = arr[0];    // LastPosition mat cow ko kaha rahoge 

    for(int i=0;i<n;i++){
        if(arr[i]-lastPosition >= mid){
            cowCount++;

            if(cowCount == k){
                return true;
            }
            lastPosition = arr[i];
        }
    }
    return false;
}

int main(){
    int k,n;     // m = number of cows   n = number of stalls
	cout<<"Enter the number of cows: ";
	cin>>k;
	cout<<"Enter the number of stalls: ";
	cin>>n;
	
	vector <int> arr;     // These is used to store array of distance between cows
	int dis = 0;            // Initially we have not pushed distances so 0
	cout<<"Enter distance of each stall: ";
	for(int i=0;i<n;i++){
		cin>>dis;
		arr.push_back(dis);  // Puts all value of dis in arr one by one
	}

    sort(arr.begin(),arr.end());   // Sorts the array in ascending order

    int start = arr[0];
    long long maxi = -1;
    
    for(int i=0;i<n;i++){
        maxi = max(maxi,(long long)arr[i]);  // Here maxi is long long so arr is also tarnsformed into long ong
    }

    long long end = maxi;
    long long ans = -1;

    while(start<=end){
        long long mid = start +(end-start)/2;

            if(isPossible(arr,k,n,mid)){
                ans  = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
    }
    cout<<"The Maximum Possible Distance between cows is: "<<ans<<endl;
    return 0;
}