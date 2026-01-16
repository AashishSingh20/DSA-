#include<iostream>
using namespace std;

int main(){
	char A[] = "welcome";
	char B[8];
	int i = 0;
	
	for(i=0;A[i]!='\0';i++){
	}
	i -= 1;
	
	int j=0;
	while(i>=0){
		B[j] = A[i];
		i--;
		j++;
	}
	B[j] = '\0';
	cout<<"Reverse of the String: "<<B<<endl;
}
