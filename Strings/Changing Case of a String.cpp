#include<iostream>
using namespace std;

int main(){
	char S[] = "WELCOME";
	cout<<"In Capital case: "<<S<<endl;
	for(int i=0;S[i]!= '\0'; i++){
		S[i] = S[i]+32;
	}
	cout<<"In small case: "<<S;
}
