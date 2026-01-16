#include<iostream>
using namespace std;

struct Array{
	int *A;
	int size;
	int length;
};

void display(struct Array arr){
	cout<<"Array: ";
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i];
	}
}

int main(){
	
	struct Array arr1;
	int ch;
	int x,index;
	
	int n;
	cout<<"Enter size of the Array: ";
    arr1.A = new int[arr1.size];
    
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
    	        Insert(&arr1,index,x);
    	        break;
    	        
    	case 2: cout<<"Enter index to be Deleted: "
		        cin>>index;
				x = Delete(&arr1,index);
				cout<<"Deleted Element is: "<<x;
				break;
				
		case 3: cout<<"Enter element to Search: ";
		        cin>>x;
				index = LinearSearch(&arr1,x);
				cout<<"Element is at Index: "<<index;
				break;
				
		case 4: cout<<"Sum is: "<<Sum(arr1);
		        break;
				
		case 5: Display(arr1);						        
	   }
	}while(ch<6);
}
