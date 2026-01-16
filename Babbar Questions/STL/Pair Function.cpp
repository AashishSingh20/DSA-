#include<iostream>
using namespace std;

int main(){
	pair<int, int> p = {1,3};
	cout<<p.first<<" "<<p.second<<endl;  // Used when you have to return to values together;
	
	pair<int,pair<int, int>> p = {1,{3,4}};
	cout<<p.first<<" "<<p1.second.second<<" "<<p1.second.first<<endl; // Sare elements 1 by one nikal ke dega
	
	pair<int, int> arr[] = {{1,2},{2,5},{5,1}};
	cout<<arr[1].second<<endl;  // 2nd array se 5 nikal ke dega
}
