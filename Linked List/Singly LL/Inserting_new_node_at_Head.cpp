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
            this->data = data;
            this->next = NULL;
        }
};

void Insert(Node* &head,int data){  // By reference le rahe hai taki copy na banana pade saari changes in original LL
// New Node creating and inserting at Head
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
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

// Head pointed to node1
    Node* head = node1;

// Insertion into the LL
    cout<<"Before Insertion: ";
    print(head);

    Insert(head,10);
    cout<<"After Insertion at Head(1): ";
    print(head);
    
    Insert(head,20);
    cout<<"After Insertion at Head(2): ";
    print(head);
}