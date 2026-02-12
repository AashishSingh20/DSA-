// Book Allocation Problem
#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>& arr,int n,int m,int mid){  // Function to check Allocation is Possible
	int StudentCount = 1;
	int PageSum = 0;
	for(int i=0;i<n;i++){
		if (arr[i] > mid)  // if single book > mid, not possible
		    return false;

		if(PageSum + arr[i] <= mid){    // If a single book has more pages than mid, it's impossible	
			PageSum += arr[i];
		}
		else{
			StudentCount++;

			if(StudentCount > m || arr[i] > mid)
			return false;
		PageSum = arr[i];
		}
	}
	return true;
}

int main(){
	int m,n;     // m = number of students   n = number of books
	cout<<"Enter the number of students: ";
	cin>>m;
	cout<<"Enter the number of books: ";
	cin>>n;
	
	vector <int> arr;     // These are number of pages per book
	int p = 0;
	cout<<"Enter pages for each book: ";
	for(int i=0;i<n;i++){
		cin>>p;
		arr.push_back(p);  // Puts all value of p in arr one by one
	}
	
	int low = 0;   // s = start of the array
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += arr[i];
	}
	int high = sum;    // e = end of array
	int ans = -1;     // This stores answer
	
	while(low<=high){
		int mid = low+(high-low)/2;
		
		if(isPossible(arr,n,m,mid)){     // If partitioning possible hoga toh ye kaam karega
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	cout << "The minimum possible maximum pages allocated to a student is: " << ans << endl;
}