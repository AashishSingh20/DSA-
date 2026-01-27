#include<iostream>
#include<queue>
using namespace std;

int main(){
    deque<int> d;   // Here we have created a doubly ended queue

    d.push_front(10); // Pushes 10 to the front
    d.push_front(5);   // Pushes 5 to the front
    d.push_back(20);  // Pushes 20 to the back

    cout<<"Front: "<<d.front()<<endl;  // Prints value at front(Here it is 5)
    cout<<"Back: "<<d.back()<<endl;  // Prints value at back(Here it is 20)

    d.pop_back();  // Pops element at back(Here it pops 20)
    d.pop_front();  // Pops element from front(Here it pops 5)
}