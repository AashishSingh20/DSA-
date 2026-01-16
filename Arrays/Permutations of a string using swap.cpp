#include<iostream>
#include<string>
using namespace std;

class Permutation{
	private:
		string s;
		int n;
		
	public:
		Permutation(string str){
			s = str;
			n = s.size();
		}
		
		
	void permuter(int l, int h);
	void Generate();		
};

void Permutation::permuter(int l, int h){
	if(l==h){
		cout<<s<<endl;
	}
	else{
		for(int i=l;i<=h;i++){
			swap(s[l],s[i]);
			permuter(l+1,h);
			swap(s[l],s[i]);
		}
	}
}

void Permutation::Generate(){
	cout<<"Permutations of the String are: "<<endl;
	permuter(0,n-1);
}


int main(){
	string input;
	cout<<"Enter a String: ";
	cin>>input;
	
	Permutation p(input);
	p.Generate();
}
