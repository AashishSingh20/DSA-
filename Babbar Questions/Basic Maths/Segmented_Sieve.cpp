// NOT COMPLETED YET

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;

    vector<bool> prime(n+1,true);
    prime[0] = prime[1] = false;
    int count = 0;
    vector<int> ans;

    for(int i=2;i<n;i++){
        if(prime[i]){
            count++;
            ans.push_back(i);

            for(int j=i*i;j<n;j=j+i){
                prime[j] = nfalse;
            }
        }
    }
}