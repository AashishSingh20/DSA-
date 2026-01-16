#include<iostream>
using namespace std;

class Node{
// Data members of class Node
    public:
        int data;
        Node* next;  

// Constructor
    public:
        Node(int data){
            this->data = data;  // data
            this->next = NULL;  // Next pointer ko NULL Par Point kar dega
        }
};

void Insert(Node* &tail,int data){  // By reference le rahe hai taki copy na banana pade saari changes in original LL
// New Node creating and inserting at Tail
    Node* temp = new Node(data);
    tail->next = temp;   // Tail ka pointer ab temp ko pointer karega
    tail = temp;   // Tail to update karke temp ko dedo abd new tail is temp
}

void print(Node* &head){  // Same as as above for taking by reference
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
// Created a new Node
    Node* node1 = new Node(2); 

// Head pointed to node1 and tail is created to find tail and insert at tail
    Node* head = node1;
    Node* tail = node1;

// Insertion into the LL
    cout<<"Before Insertion: ";
    print(head);

    Insert(tail,10);
    cout<<"After Insertion at Tail(1): ";
    print(head);

    Insert(tail,20);
    cout<<"After Insertion at Tail(2): ";
    print(head);
}