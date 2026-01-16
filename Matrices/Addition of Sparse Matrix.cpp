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

struct Sparse * add(struct Sparse *s1, struct Sparse *s2)
{
	struct Sparse *sum;
	sum = new Sparse;
	sum->ele = new Element[s1->num+s2->num];
	int i,j,k;
	i=j=k=0;
	
	while(i<s1->num && j<s2->num){
		if(s1->ele[i].i < s2->ele[j].i){
			sum->ele[k] = s1->ele[i];    // s1 ka row chhota hai toh usse input mein dalo
			i++;
			k++;
		}
		
		else if(s1->ele[i].i > s2->ele[j].i){
			sum->ele[k] = s2->ele[j];   // s2 ke row chhota hai togh usse input mein dalo
			j++;
			k++;
		}
		
		else{                                     // dono row barabar hai toh ismein jao
			if(s1->ele[i].j < s2->ele[j].j){   // agar s1 ka column s2 se chhota hai toh usse pehle dalo
				sum->ele[k] = s1->ele[i];
				i++;
				k++;
			}
			
			else if(s1->ele[i].j > s2->ele[j].j){  // agar s2 ka column s1 se chhota hai toh usse pehle dalo
				sum->ele[k] = s2->ele[j];
				j++;
				k++;
			}
			
			else{
				sum->ele[k] = s1->ele[i];      // agar dono s1 and s2 same hai toh element add karke dalo, yaha ele[i] yaa ele[j] kuch bhi likh sakte hai
				sum->ele[k].x = s1->ele[i].x + s2->ele[j].x;   // s2 ke element ko bhi aad karlo ele[k] mein
				i++; 
				j++;           
				k++;
			}
		}
	}
	
	for(;i<s1->num;i++){
		sum->ele[k] = s1->ele[i];
		k++;
	}
		
	for(;j<s2->num;j++){
		sum->ele[k] = s2->ele[j];
		k++;
	}
	sum->m = s1->m;
	sum->n = s1->n;
	sum->num = k;
	
	return sum;

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
	struct Sparse s1,s2,*s3;
	Create(&s1);
	Create(&s2);
	
	s3 = add(&s1,&s2);
	
	cout<<"First Matrix: "<<endl;
	Display(s1);
	
	cout<<"Second Matrix: "<<endl;
	Display(s2);
	
	cout<<"Sum of Both Matrix: "<<endl;
	Display(*s3);
}
