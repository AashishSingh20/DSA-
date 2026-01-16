#include<iostream>
#include<string>
using namespace std;

int main(){
	string name;
	cout<<"Enter a name: ";
	cin>>name;
	
	string B = name;
	int i = 0;
	int j = B.length()-1;
	
	while(i>=0){
		i++;
		j--;
		
		if(name[i]!=B[j]){
			cout<<"String is not a Palindrome.";
			break;
		}
		else{
			cout<<"String is a Palindrome.";
			break;
		}		
	}
}
