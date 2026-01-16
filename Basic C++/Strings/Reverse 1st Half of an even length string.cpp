#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s = "Madhav";
	cout<<s<<endl;
	int l = s.length();  // l = 6
	
//	int i = 0;               // METHOD 1
//	int j = l/2 - 1;
//	while(i<j){
//		char temp = s[i];
//		s[i] = s[j];
//		s[j] = temp;
//		i++;
//		j--;
//	}

    reverse(s.begin(),s.begin()+l/2);   // METHOD 2
	cout<<s;
}
