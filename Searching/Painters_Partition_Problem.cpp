#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector <int>& arr, int k, int n, int mid){
    int LengthSum = 0;      // sum of all length of boards in array
    int PainterCount = 1;   // Number of painters to whom work is assigned

    for(int i=0;i<n;i++){
        if (arr[i] > mid){  // if length of one board > mid, then not possible
		    return false;
        }
        else if(LengthSum + arr[i] <= mid){  // if Length of book is <= mid the segmenting is possible otherwise not
            LengthSum += arr[i];     // If possible then board size
        }
        else{
            PainterCount++;    // If the above statment is false then goto next painter
            if(PainterCount > k || arr[i] > mid){   // If Painter is more than mentioned or length of board is greater than mid then return false
                return false;
            }
            LengthSum = arr[i];    // Put sum of all elements in the array left into LengthSum
        }
    }
    return true;    // If conditions segentation is Possible then this function will work
}

int main(){
    int k,n;     // k = number of painters   n = number of boards
	cout<<"Enter the number of painters: ";
	cin>>k;
	cout<<"Enter the number of boards: ";
	cin>>n;
	
	vector <int> arr;     // These is used to store the length of boards
	int l = 0;            // Initially length of each board is 0 then value are put one by through loop
	cout<<"Enter length of each board: ";
	for(int i=0;i<n;i++){
		cin>>l;
		arr.push_back(l);  // Puts all value of p in arr one by one
	}

    int start = 0;   // Start is at 0
    int ans = -1;   // This is used to store minimum time required to complete the painting job
    int sum = 0;     // This sums all 
    int maxBoard = 0;  
    for(int i=0;i<n;i++){   // Sums length of all boards and gives it to end as upper limit
        sum += arr[i];
        maxBoard = max(maxBoard,arr[i]);
    }

    start = maxBoard;
    int end = sum;   // End of the Array 

    while(start<=end){
        int mid = start + (end-start)/2;

        if(isPossible(arr,k,n,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid+1;
        }
    }
    cout << "The minimum possible time required by painters is: " << ans << endl;
}