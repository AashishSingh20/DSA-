#include<iostream>
using namespace std;

class Element{
	public:
		int i;  // Row of the element
		int j;  // Column of the element
		int x;  // Element
};

class Sparse{
	private:
		int m;
		int n;
		int num;
		Element *ele;
		
	public:
		Sparse(int m, int n, int num){
			this->m = m;
			this->n = n;
			this->num = num;
			ele = new Element[this->num];
		}
		
		~Sparse(){
			delete []ele;
		}
		
		void Read(){
			cout<<"Enter non-Zero Elements: "<<endl;
			for(int i=0;i<num;i++){
				cin>>ele[i].i>>ele[i].j>>ele[i].x;  // Row, column and Element ko insert karega
			}
		}
		
		void Display(){
			cout<<"Matrix: "<<endl;
			int k = 0;
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(ele[k].i == i && ele[k].j == j){  // Check karega ki row index of Kth element current row 'i' se match karta hai yaa nahi AND column index of Kth element current column 'j' ke barebar hai ki nahi.  
						cout<<ele[k].x<<" ";   // Element display hoga
						k++;  // Current Element par point karega hai
					}
					else{
						cout<<"0 ";
					}
				}
				cout<<endl;
			}
		}	
};

int main(){
	Sparse s1(5,5,5);
		s1.Read();
		s1.Display();
}
