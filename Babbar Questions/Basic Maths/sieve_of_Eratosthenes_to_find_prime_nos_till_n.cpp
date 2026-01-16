#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter no: ";
    cin>>n;

    int count = 0;  // To track number prime nos till n
    vector<bool> prime(n+1,true);  // It declares all number as Prime
    prime[0] = prime[1] = false;   // It states that 0 and 1 are not prime

    for(int i=2;i<n;i++){
        if(prime[i]){  // Checks if the number is prime, if it is then increase count by 1
            count++;
            
            for(int j=i*i;j<=n;j=j+i){  // i ke saare multiples ko non prime mark kar dega.
                prime[j] = 0;
            }
        }
    }
    cout<<"Prime Numbers between 1 and "<<n<<" is "<<count<<endl;
}