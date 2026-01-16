#include<iostream>
using namespace std;

int SquareRoot(int n){
	long long int sqrt = -1;  // Yeh squareroot ki value to store karega.
	long long int low = 0;
	long long int high = n;
	
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

double morePrecision(int n, int precision, int result){
	double factor = 1; // Initially 1 isliye rakha hau kyuki jab isse 10 se divide karenge toh 0.1 aayega.
	double ans = result;
	
	for(int i=0;i<precision;i++){
		factor = factor/10;    //(1st iteration = 0.1, 2nd iteration = 0.01, 3rd = 0.001, ......)
		
		for(double j=ans;j*j<n;j = j+factor){
			ans = j;
		}
	}
	return ans;
}

int main(){
	int num;
	cout<<"Enter number whose square root you want to find: ";
	cin>>num;
	
	int result = SquareRoot(num);
	cout<<"Square root of "<<num<<" is: "<<morePrecision(num,3,result)<<endl;
}	
