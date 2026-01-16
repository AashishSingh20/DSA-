#include <iostream>
using namespace std;

int sumEle(int *arr, int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }

    int sum = arr[0];
    return sum+sumEle(arr+1,n-1);
}

int main(){
    int n;
    cout<<"Enter Array size: ";
    cin>>n;
    int *arr = new int[n];

    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = sumEle(arr, n);
    cout<<"Sum of all Elements in the Array: "<<ans<<endl;

    delete[]arr;
}