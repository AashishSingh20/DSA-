#include<iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
        
    public:
        Array(int arr[], int n){
            size = n;
            length = n;
            A = new int[n];
            for(int i = 0; i < n; i++){
                A[i] = arr[i];
            }
        }

        void Display(){    
            for(int i=0;i<length;i++){
                cout<<A[i]<<" ";
            }
            cout<<endl;
        }

        void Reverse(){
            int i = 0;
            int j = length - 1;
            while(i < j){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
                j--;
            }
        }

        ~Array(){
            delete[] A;
        }
};

int main(){
    int arr[] = {12,44,23,2,4,5,2,45,53};
    int n = sizeof(arr)/sizeof(arr[0]);

    Array obj(arr, n);

    obj.Display();
    obj.Reverse();
    obj.Display();
}
