#include<iostream>
using namespace std;

int main(){
	char A[] = "Hello how Are you";
	int word = 1;
	for(int i=0;A[i]!='\0';i++){
		if(A[i] == ' ' && A[i-1] != ' '){
			word++;
		}
	}
	cout<<"Total Number of Words in the string: "<<word;
}
