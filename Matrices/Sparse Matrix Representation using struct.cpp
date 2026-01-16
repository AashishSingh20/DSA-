#include<iostream>
using namespace std;

struct Element{
	int i;  // row
	int j;  // col
	int x;  // value
};

struct Sparse{
	int m;   // rows
	int n;   // columns
	int num;  // no of non-zero elements
	struct Element *ele;   // dynamic array ele is created
};

void Create(struct Sparse *s){
	cout<<"Enter Dimensions: ";
	cin>>s->m>>s->n;
	cout<<"Enter no of non-zero Elements: ";
	cin>>s->num;
	
	s->ele = new Element[s->num];
	cout<<"Enter non-zero Elements: "<<endl;
	for(int i=0;i<s->num;i++){
		cin>>s->ele[i].i>>s->ele[i].j>>s->ele[i].x;  // we first input row, then column, the the element
	}
}

void Display(struct Sparse s){
	int k = 0;
	cout<<"Matrix: "<<endl;
	for(int i=0;i<s.m;i++){
		for(int j=0;j<s.n;j++){
			if(k<s.num && i==s.ele[k].i && j==s.ele[k].j){
				cout<<s.ele[k].x<<" ";
				k++;
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
}

int main(){
	struct Sparse s;
	Create(&s);
	Display(s);
}
