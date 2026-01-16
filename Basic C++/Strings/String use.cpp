#include<iostream>
using namespace std;

int main(){
	string s;
	cout<<"Enter a string: ";
	getline(cin,s);  // Used to get full sentences in string
	cout<<s<<endl;
	cout<<s[0]<<endl;  // Prints charcter at 0th index in the string
	
	s[0] = 'A';  // Update the chracter at the 0th Index
	cout<<s<<endl;
	
	cout<<s.length()<<endl;  // Used to find the length of the string

}
