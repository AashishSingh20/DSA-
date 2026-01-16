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
		
		friend istream & operator>>(istream &is, Sparse &s);  // For Read - Extraction operator hai ye read karne ke liye best hai(sare words same rehange bas 'Sparse &s' wala part condition ke hisab se change hoga.
		friend ostream & operator<<(ostream &os, Sparse &s);  // For Display - Insertion Operator hai yeh Display karne ke liye use hota hai(sare words same bas 'Sparse &s' change hoga depending on condition)
		
};

		istream & operator>>(istream &is, Sparse &s){
			cout<<"Enter non-Zero Elements: "<<endl;
			for(int i=0;i<s.num;i++){
				cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;  // Row, column and Element ko insert karega
			}
			return is;	
		}
		
		ostream & operator<<(ostream &os, Sparse &s){
			cout<<"Matrix: "<<endl;
			int k = 0;
			for(int i=0;i<s.m;i++){
				for(int j=0;j<s.n;j++){
					if(s.ele[k].i == i && s.ele[k].j == j){  // Check karega ki row index of Kth element current row 'i' se match karta hai yaa nahi AND column index of Kth element current column 'j' ke barebar hai ki nahi.  
						cout<<s.ele[k].x<<" ";   // Element display hoga
						k++;  // Current Element par point karega hai
					}
					else{
						cout<<"0 ";
					}
				}
				cout<<endl;
			}
			return os;
		}	

int main(){
	Sparse s1(5,5,5);
		cin>>s1;
		cout<<s1;
}
