#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,ele;
    cout<<"Enter number of Elements in Array: ";
    cin>>n;

    cout<<"Enter Array Elements: ";
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    
    int k;
    cout<<"Enter by how many position you want to rotate array: ";
    cin>>k;

    vector<int> temp(n);   // We will put all rotated values in this Array
    for(int i=0;i<n;i++){   
        temp[(i+k)%n] = arr[i];  // If k = 12 and n = 10 then it will use mod and set k = 2 as remaider of 12/10 is 2
    }

    for(int i=0;i<n;i++){   // Here temp is putting all it's value after rotation into array
        arr[i] = temp[i];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}