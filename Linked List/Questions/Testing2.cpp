#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
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

Node* getIntersection(Node* &head){
    if(head == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* &head){
    if(head == NULL){
        return head;
    }

    Node* intersection = getIntersection(head);
    if(intersection == NULL){
        return NULL;
    }
    Node* temp = head;

    while(temp != intersection){
        temp = temp->next;
        intersection = intersection->next;
    }
    return temp;
}

void removeLoop(Node* &head){
    if(head == NULL){
        return;
    }

    Node* startingOfLoop = getStartingNode(head);
    if(startingOfLoop == NULL){
        return;
    }

    Node* temp = startingOfLoop;
    while(temp->next != startingOfLoop){
        temp = temp->next;
    }
    temp->next = NULL;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* g = new Node(70);
    Node* h = new Node(80);
    
    Node *head = a;
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = b;
    h->next = NULL;
    
    if(getIntersection(head)){
        cout<<"List has a Loop."<<endl;
        cout<<"Loop starts from Node: "<<getStartingNode(head)->data<<endl;
        removeLoop(head);   // Bina iske loop infinite loop mein fas jata
        cout<<"After Removing Loop in LL: ";
    }
    else{
        cout<<"List does not have a Loop.";
    }

    print(head);
}