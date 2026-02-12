#include<iostream>
#include<vector>
using namespace std;

int main(){
    int length,ele;
    cout<<"Enter Length of the array: ";
    cin>>length;

    vector <int> arr;
    cout<<"Enter Elements: ";
    for(int i=0;i<length;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    for(int i=0;i<length-1;i++){       // For round 1 to n-1
        bool swapped = false;          // Agar kisi round mein kuch swap nahi hoga toh ye loop se bahar nikal dega
        for(int j=0;j<length-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;     // Agar swap hua matlab sorting ho rahi hai so loop continues
            }
        }
        if(swapped == false){   // Agar ek bhi swap nahi hua kisi round mein matlab already sorted hai break kardo loop ko
            break;
        }
    }
    cout<<"Sorted Array is: ";
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}