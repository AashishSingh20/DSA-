#include<iostream>
using namespace std;

class Array{
	private:
		int *A;
		int size;
		int length;
		
	public:
		Array(int sz){
			size = sz;
			length = 0;
			A = new int[size];
		}
		
		~Array(){
			delete []A;
		}
		
		void Fill(int data[],int n){
			length = n;
			for(int i=0;i<n;i++){
				A[i] = data[i];
			}
		}
		
		void Display();
		void Sort012(int arr[]);
};

void Array::Display(){
	cout<<"Array: ";
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void Array::Sort012(int arr[]){
	int low=0;  // Low ko initially 0 par set karo
	int mid=0;   // mid ko bhi 0 par set karo
	int high=length-1;   // high ko last mein set karo
	
	while(mid<=high){   // jabtak mid high ke kam yaa barabar hai tabtak loop
		if(A[mid]==0){   // Agar mid ka element '0' nikal gaya then 
			swap(A[mid],A[low]);  // swap low with mid element
			low++;  // low ko aage badhado since first element is sorted
			mid++;  // mid ko bhi badhado  since first element has been sorted
		}
		else if(A[mid]==1){  // Agar mid 1 ke barabar aa gaya then mid ko aage badha do lo ko wahi rehne do
			mid++;
		}
		else{
			swap(A[mid],A[high]);  // Aur agar mid '2' aa gaya then high se usko swap mardo
			high--;  // aur high ko aage badhado kyuki last element has already become sorted
		}
	}
}

int main(){
	Array arr(10);
	int data[] = {1,2,0,1,0,2,1,2,0};
	int n = sizeof(data)/sizeof(data[0]);
	arr.Fill(data,n);
	arr.Display();
	
	arr.Sort012(data);
	arr.Display();
}
