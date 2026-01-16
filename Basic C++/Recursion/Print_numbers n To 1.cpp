#include<iostream>
using namespace std;
void print(int n){
	if(n==0){    // Base Case
		return;
	}else{
	    cout<<n<<endl;  // Work
		print(n-1);  // Call
	}
}

int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;
	
	print(n);
}
