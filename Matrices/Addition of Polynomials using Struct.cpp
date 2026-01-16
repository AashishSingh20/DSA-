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
		cout<<p.terms[i].coeff<<"x^"<<p.terms[i].exp;
		    if (i != p.n - 1){
			cout << " + ";
		}
	}
	cout<<endl;
}

struct Poly *add(struct Poly *p1, struct Poly *p2){
	Poly *sum = new Poly;
	sum->terms = new Term[p1->n + p2->n];
	
	int i=0, j=0, k=0;
	
	while(i<p1->n && j<p2->n){
		if(p1->terms[i].exp > p2->terms[j].exp){
			sum->terms[k] = p1->terms[i];
			i++;
			k++;
		}
		
		else if(p1->terms[i].exp < p2->terms[j].exp){
			sum->terms[k] = p2->terms[j];
			j++;
			k++;
		}
		
		else{
			sum->terms[k].exp = p1->terms[i].exp;
			sum->terms[k].coeff = p1->terms[i].coeff + p2->terms[j].coeff;
			i++;
			j++;
			k++;
		}
	}
	
	for(;i<p1->n;i++){
		sum->terms[k] = p1->terms[i];
		k++;
	}
	for(;j<p2->n;j++){
		sum->terms[k] = p2->terms[j];
		k++;
	}	
	
	sum->n = k; // Sum's no of Element should be equal to k
	
	return sum;
}

int main(){
	
	struct Poly p1,p2,*p3;
	
	create(&p1);
	create(&p2);
	
	p3 = add(&p1,&p2);
	cout<<endl;
	Display(p1);
	cout<<endl;
	Display(p2);
	cout<<endl;
	Display(*p3);
	
}
	
