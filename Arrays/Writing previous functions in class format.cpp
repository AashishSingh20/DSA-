#include<iostream>
using namespace std;

class Array{
	private:
		int *A;
		int size;
		int length;
		void swap(int *x, int *y)
		
	public:
	    Array(){
	    	size = 10;
	    	length = 0;
	    	A = new int[size];
		}
		Array (int sz){
			size =10;
			length = 0;
			A = new int[size];
		}
		~Array(){
			delete []A;
		}
		
	void Display();
	void Append(int x);
	void Insert(int index, int x)
	int LinearSearch(int key);
	int BinarySearch(int key);
	int Get(int index);
	int Set(int index, int x);
	int Max();
	int Min();
	int Sum();
	float Avg();
	void Reverse();
	void Reverse2();
	void InserSort(int x);
	void isSorted();
	void Rearrange();
	Array* Merge(Array *arr2);
	Array* Union(Array *arr2);
	Array* Intersection(Array *arr2);
	Array* Difference(Array *arr2);
// Write all funtions that we created previously
};

void Array::Display(){
	int i;
	cout<<"Array: ";
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
}

// Do same for the other functions

int main(){
		
	struct *arr1;
	int ch,sz;
	int x,index;
	
	int n;
	cout<<"Enter size of the Array: ";
    arr1 = new Array(sz);
    
    cout<<"Menu:"<<endl;
    cout<<"1. Insert"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Search"<<endl;
    cout<<"4. Sum"<<endl;
    cout<<"5. Display"<<endl;
    cout<<"6. Exit"<<endl;
    
    cout<<"Enter your choice: ";
    cin>>ch;
    do{
    switch(ch){
    	case 1: cout<<"Enter an element and index: ";
    	        cin>>x>>index;
    	        arr1.Insert(index,x);
    	        break;
    	        
    	case 2: cout<<"Enter index to be Deleted: "
		        cin>>index;
				x = arr1.Delete(index);
				cout<<"Deleted Element is: "<<x;
				break;
				
		case 3: cout<<"Enter element to Search: ";
		        cin>>x;
				index = arr1.LinearSearch(x);
				cout<<"Element is at Index: "<<index;
				break;
				
		case 4: cout<<"Sum is: "<<arr1.Sum();
		        break;
				
		case 5: arr1.Display();						        
	   }
	}while(ch<6);
}
