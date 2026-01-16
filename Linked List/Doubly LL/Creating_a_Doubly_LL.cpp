#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    public: 
    // Constructor
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
    
    // Destructor
        ~Node(){
        }
};

// Traversing and Printing a Linked List
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Gets the Length of Linked List
int getLength(Node* &head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}


int main(){
    Node* node1 = new Node(10);
    Node* head = node1;

    print(head);
    cout<<"Length of LL:"<<getLength(head)<<endl;
    
    delete node1;
}