#include<iostream>
using namespace std;

int SquareRoot(int n){
	long long int sqrt = -1;  // Yeh squareroot ki value to store karega.
	long long int low = 0;
	long long int high = n-1;
	
	while(low<=high){
		long long int mid = low+(high-low)/2;
		long long int square = mid*mid;
		
		if(square == n){
			return mid;
		}
		
		else if(square < n){
			sqrt = mid;
			low = mid+1;
		}
		
		else{
			high = mid-1;
		}
	}
	return sqrt;
}

int main(){
	int num;
	cout<<"Enter number whose square root you want to find: ";
	cin>>num;
	
	int result = SquareRoot(num);
	cout<<"Square root of "<<num<<" is: "<<result<<endl;
}
