#include<iostream>
using namespace std;

int e(int x, int n){
	int s=1;
	for(n>0;n--){
		s= 1+x*s/n;
		return s;
	}
}

int main(){
	int x,n;
}
