#include<iostream>
using namespace std;

struct Term{
	int coeff;  // Coefficient (Number before x)
	int exp;   // Exponent (Power of x)
};

struct Poly{
	int n;
	struct Term *terms;
};

void create(struct Poly *p){
	cout<<"Enter the number of Terms: ";
	cin>>p->n;
	p->terms = new Term[p->n];
	
	cout<<"Enter the Terms: ";
	for(int i=0;i<p->n;i++){
		cin>>p->terms[i].coeff>>p->terms[i].exp;
	}
}

void Display(struct Poly p){
	for(int i=0;i<p.n;i++){
		cout<<p.terms[i].coeff<<"x^"<<p.terms[i].exp<<" + ";
	}
	cout<<endl;
}

int main(){
	
	struct Poly p1;
	
	create(&p1);
	Display(p1);
	
	delete[] p1.terms;
}
