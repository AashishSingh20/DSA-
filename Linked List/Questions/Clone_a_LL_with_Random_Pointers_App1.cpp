#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* random;
        
    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
};

void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node* &head){
    Node* temp = head;
    if(temp == NULL){
        cout<<"List is Empty.";
        return;
    }
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* copyRandomList(Node* head){
    // Step 1:- create a Clone List using next Pointer
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
        
    Node* temp = head;
    while(temp != NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }
    
    // Step 2:- Create a Map
    unordered_map<Node*, Node*> oldToNew;
    
    Node* originalNode = head;  // Point to the head of Original List
    Node* cloneNode = cloneHead;  // Points to the Head of Copy List
    while(originalNode != NULL){
        oldToNew[originalNode] = cloneNode;  // Original Nodes ko Clone Nodes se map kardo
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    
    // Step 3:- Arrange the Random Pointers
    originalNode = head;
    cloneNode = cloneHead;
    
    while(originalNode != NULL){
        cloneNode->random = oldToNew[originalNode->random]; // cloneNode ke random ko uspar point karo jispar original node ka random point kar raha hai
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
    
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    
    Node *head = a;
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;

    a->random = c;
    b->random = a;
    c->random = e;
    d->random = c;
    e->random = b;

    print(head);
}