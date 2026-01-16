#include<iostream>
using namespace std;

class Node{
// Data members of class Node
    public:
        int data;
        Node* next;  // Node class mein ek pointer banado next naam ka  

// Constructor
    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

int main(){
    Node* node1 = new Node(2);  // Pointer to a Node ki madad se 'node1' pointer banaya aur 'Node()' constructor is called to pass 2 to heap memory

    cout<<"Value at node 1: "<<node1->data<<endl;
    cout<<"Address of next Node: "<<node1->next<<endl;
}