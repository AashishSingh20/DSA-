#include<iostream>
using namespace std;

int main(){
	string s = "aashish";
	cout<<s<<endl;
	int count = 0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
			count += 1;
		}
	}
	cout<<"Number of vowels in the string is: "<<count;
}
