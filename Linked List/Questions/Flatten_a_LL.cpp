#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* child;
        
    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->child = NULL;
        }
};

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

Node* flattenLL(Node* head){
    
}

int main(){
    Node* a = new Node(1);
    Node* d = new Node(4);
    Node* g = new Node(7);
    Node* i = new Node(9);
    Node* k = new Node(20);
    
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* h = new Node(8);
    Node* j = new Node(12);
    
    Node *head = a;
    
    a->next = d;
    d->next = g;
    g->next = i;
    i->next = k;
    k->next = NULL;

    a->child = b;
    b->child = c;
    d->child = e;
    e->child = f;
    g->child = h;
    i->child = j;

    head = flattenLL(head);
    print(head);
}