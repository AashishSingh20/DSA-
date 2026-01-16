#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int arr[] = {3,5,6,2,1};
	int mx = arr[0];
	int n = sizeof(arr)/4; // Used to find the length of the array
	cout<<"Array: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
    }
    
    for(int i=1;i<n;i++){
//    	if(arr[i]>mx){      // METHOD 1
//    		mx = arr[i];
//		}
		mx = max(mx,arr[i]) ;  // METHOD 2
    }
    cout<<endl;
    
    cout<<"Maximum element in the array is:"<<mx;
}
