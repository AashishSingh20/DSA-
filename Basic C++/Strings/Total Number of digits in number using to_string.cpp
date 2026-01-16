#include<iostream>
#include<string>
using namespace std;

int main(){
	int x = 12345;
	string s = to_string(x);
	cout<<s<<endl;
	cout<<"Total number of digits in x: "<<s.length();
}
