#include<iostream>
#include<string>
using namespace std;

int main(){
	string name;
	cout<<"Enter a name: "; 
	cin>>name;
	
	int i = 0, j = name.length()-1;
	
	while(i<j){
		i++;
		j--;
		if(name[i]==name[j]){
			cout<<"String is a Palindrome.";
			break;
		}
		else{
			cout<<"String is not a Palindrome.";
			break;
		}
	}
}
