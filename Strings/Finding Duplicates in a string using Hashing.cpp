#include<iostream>
#include<string>
using namespace std;

int main(){
	string A;
	cout<<"Enter a string: ";
	cin>>A;
	int i;
	int H[26] = {0};
	
	for(i=0;i<A.length();i++){
		H[A[i]-97] += 1;
	}
	for(i=0;i<26;i++){
		if(H[i]>1){
			cout<<char(i+97)<<" is appearing ";  // This will print the charcters and not ASCII Codes
			cout<<H[i]<<" times";
			cout<<endl;
		}
	}
}
