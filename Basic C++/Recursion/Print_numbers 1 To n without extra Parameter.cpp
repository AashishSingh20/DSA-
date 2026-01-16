#include<iostream>
using namespace std;
void print(int n){ 
	if(n==0){    // Base Case
		return;  
	}else{
		print(n-1);  // Call
	    cout<<n<<endl; // Work
	}
}

int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;
	
	print(n);
}
