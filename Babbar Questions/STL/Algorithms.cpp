#include<iostream>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
	if(p1.second < p2,second){
		return true;
	if(p1.second > p2.second){
		return false;
	}
	else{
		return false;
	}
	
	
	if(p1.first > p2.first){
		return true;
	}
	else{
		return false;
	}	
}

int main(){
	//Sort 
	
	//{5,3,7,1,9,0}
	sort(a, a+n);  // {0,1,3,5,7,9} 
	sort(v.begin(), v.end()); // same output as above
	
	sort(a+2, a+4);  //{5,3,1,7,9,0}  // Sorted elements at index 2 and 3
	sort(a, a+n, greater<int>);  // Sorts in descending order {9,7,5,3,1,0}
	
	pair<int, int> a[] = {{1,2}, {2,1}, {4,1}};
	
	//sort it according to second element
	// If second element is same, then sort it according to the first element
	
	sort(a, a+n, comp);  	// {{4,1}, {2,1}, {1,2}}
	
	int num = 7;
	int cnt = _builtin_popcount();  // It converts the no into Binary and count the no of 1's it has.
	
	long long num = 165786578687;
	int cnt = _builtin_popcountll();
	
	string s = "123";
	sort(s.begin(), s.end());  // Sorts the string in case it is not given in a sorted manner
	
	do{
		cout<<s<<endl;
	}
	while{
		(next_permutation(s.begin(), s.end()))
	}
	
	int maxi = *max_element(a,a+n);
}
