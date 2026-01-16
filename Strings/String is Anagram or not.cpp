#include<iostream>
#include<string>
using namespace std;

int main(){
	string A,B;
	cout<<"Enter 1st String: ";
	cin>>A;
	cout<<"Enter 2nd String: ";
	cin>>B;
	
	if (A.length() != B.length()) {
        cout << "String is not an Anagram.";
        return 0;
    }
	
	int i, H[26] = {0};
	
	for(i=0;i<A.length();i++){
		H[A[i]-97] += 1;
	}
	
	for(i=0;i<B.length();i++){
		H[A[i]-97] -= 1;
		
		if(H[B[i]-97] < 0){
			cout<<"String is not an Anagram.";
			break;
		}
	}
	if(B[i] == '\0'){
		cout<<"String is an Anagram.";
	}	
}
