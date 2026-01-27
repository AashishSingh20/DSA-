#include<iostream>
#include<queue>
using namespace std;

int main(){
    
    // Create a Queue 
    queue<int> q;

    q.push(11);
    cout<<"Front is Queue is: "<<q.front()<<endl;
    cout<<"Back of Queue is: "<<q.back()<<endl;
    q.push(15);
    cout<<"Front is Queue is: "<<q.front()<<endl;
    cout<<"Back of Queue is: "<<q.back()<<endl;
    q.push(17);
    cout<<"Front is Queue is: "<<q.front()<<endl;
    cout<<"Back of Queue is: "<<q.back()<<endl;
    
    cout<<"Size of queue: "<<q.size()<<endl;

    q.pop();
    cout<<"Size of queue: "<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue id Empty!"<<endl;
    }
    else{
        cout<<"Queue is not Empty!";
    }
}