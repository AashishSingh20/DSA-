#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, ele;  // n = length of array,   ele = elements in the array
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    for(int i=1;i<n;i++){
        int temp = arr[i];   // Yeh temp hai joh i pointer ke hisab se change karega
        int j = i-1;   // Yeh i se pehle wale element ko check karne ke liye hai ki kahi woh bada toh nahi
        while(j>=0){   // jabtak j 0 se bada hai tabtak chalega
            if(arr[j] > temp){   // If element at j is greater than elemnt at temp which has element at i
                arr[j+1] = arr[j];  // j+1 wale element ko j ki  jagah daldo
                j--;   // Ab j ko peeche le jao
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;    // Temp ko correct position par insert karo
    }

    cout<<"Sorted Array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}