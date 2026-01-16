#include<iostream>
using namespace std;

int main(){
	char A[] = "Extermination";
	int Vcount = 0;
	int Ccount = 0;
	for(int i=0;A[i]!='\0';i++){
		if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' ||A[i] == 'A' ||A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U'){
		   	Vcount++;
		   }
		   
		else if((A[i]>=65 && A[i]<=90) || (A[i]>=97 and A[i]<=122)){
			Ccount++ ;
		}
	}
	cout<<"No of Vowels: "<<Vcount<<endl;
	cout<<"No of Consonents: "<<Ccount<<endl;
}
