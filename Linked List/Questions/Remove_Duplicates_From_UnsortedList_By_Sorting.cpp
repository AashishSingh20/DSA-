#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

int main(){
    list<int> ll;

    int n,ele;
    cout<<"Enter How Many Elemets in the LL: ";
    cin>>n;

    cout<<"Enter LL Elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        ll.push_back(ele); // Inserts elements in the LL from Behind
    }

    ll.sort();
    ll.unique();

    cout<<"After sorting and Removing Duplicates: ";
    for(int x: ll){
        cout<<x<<" ";
    }
    cout<<endl;
}