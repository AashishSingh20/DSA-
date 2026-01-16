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
		int m;  // Rows of sparse Matrix 
		int n;  // Columns of Sparse Matrix
		int num;  // Total no of Elements in the sparse Matrix
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
		
		Sparse operator+(Sparse	&s);
		friend istream & operator>>(istream &is, Sparse &s);  // For Read - Extraction operator hai ye read karne ke liye best hai(sare words same rehange bas 'Sparse &s' wala part condition ke hisab se change hoga.
		friend ostream & operator<<(ostream &os, Sparse &s);  // For Display - Insertion Operator hai yeh Display karne ke liye use hota hai(sare words same bas 'Sparse &s' change hoga depending on condition)
		
};

Sparse Sparse::operator+(Sparse &s){
	int i,j,k;
	i=j=k=0;
	if(m != s.m || n != s.n){
		cout<<"Matrix Dimensions do not Match.";
	}
	Sparse *sum = new Sparse(m,n,num+s.num);
	
	while(i<num && j<s.num){
		if(ele[i].i < s.ele[j].i){
			sum->ele[k] = ele[i];
			i++;
			k++;
		}
		else if(ele[i].i > s.ele[j].i){
			sum->ele[k] = s.ele[j];
			j++;
			k++;
		}
		else{
			if(ele[i].j < s.ele[j].j){
				sum->ele[k] = ele[i];
				i++;
				k++;
			}
			else if(ele[i].j > s.ele[j].j){
				sum->ele[k] = s.ele[j];
				j++;
				k++;
			}
			else{
				sum->ele[k] = ele[i];
				sum->ele[k].x = ele[i].x + s.ele[j].x;
				i++;
				j++;
				k++;
			}
		}
	}
	
	for(;i<num;i++){
		sum->ele[k] = ele[i];
		k++;
	}
	
	for(;j<s.num;j++){
		sum->ele[k] = s.ele[j];
		k++;
	}
	sum->num = k;
	
	return *sum;
}	

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
	Sparse s2(5,5,5);
	
	cin>>s1;
	cin>>s2;
	
	Sparse sum = s1+s2;
	
	cout<<"First Matrix: "<<endl<<s1;
	cout<<"Second Matrix: "<<endl<<s2;
	cout<<"Sum of Matrices: "<<endl<<sum;
}
