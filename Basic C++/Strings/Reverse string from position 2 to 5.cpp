#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s = "Madhav";
	cout<<s<<endl;
	int l = s.length();  // l = 6
		
    reverse(s.begin()+1,s.begin()+5);
	cout<<s;
}
