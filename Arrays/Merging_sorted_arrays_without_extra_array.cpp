#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr1,int n1, vector<int>& arr2, int n2){
    
    // i j and k last se start karenge warna bich ke elements kho jayenge array ke
    int i = n1 - 1; // Last Valid element in arr1
    int j = n2 - 1;  // Last Valid element in arr2
    int k = n1 + n2 - 1;  // Last Element index of merged array
    
    while(i>=0 && j>=0){
        if(arr1[i] > arr2[j]){  // Agar arr1 ka element arr2 se bada hai toh arr1 ke element ko last mein daldo
            arr1[k] = arr1[i]; 
            k--;   
            i--;
        }
        else{
            arr1[k] = arr2[j];  // Agar arr2 ke element arr1 se bade hai toh arr2 ke element ko last mein daldo
            k--;
            j--;
        }
    }
    
    while(j>=0){
        arr1[k--] = arr2[j--];  // agar arr2 mein koi element bach jaye toh usse daldo
    }
}

void print(vector<int> arr1,int n3){
    for(int i=0;i<n3;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n1,n2,ele;
    
    cout<<"Enter size of Array 1: ";
    cin>>n1;
    
    cout<<"Enter size of Array 2: ";
    cin>>n2;
    
    vector<int> arr1(n1+n2);  // size of arr1, array 1 and arr2 ke size se milke banega
    
    cout<<"Enter Array1 Elements: ";  
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cout<<endl;
    
    vector<int> arr2(n2);  // Size of arr2 mein yahapar hi bata diya hai toh push back nahi karenge error hoga
    cout<<"Enter Array2 Elements: ";
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    cout<<endl;
    
    merge(arr1, n1, arr2, n2);
    print(arr1, n1+n2);
}