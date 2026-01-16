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
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    if(head->next == NULL){
        return NULL;
    }
    while(fast != NULL && fast->next != NULL){  // Loop until 'fast' wala node is not NULL or 'fast' ka next node is not NULL
        fast = fast->next->next;  // 'fast' ko 2 - 2 step badhate jao
        slow = slow->next;  // 'slow' ko 1 - 1 step badhate jao
        if(slow == fast){  // Jab 'fast' catches 'slow' that means loop is present
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* &head){
    if(head == NULL){
        return NULL;
    }

    Node* intersection = getIntersection(head);  // Stores the location at which fast and slow meet 
    cout<<"Fast catches slow at: "<<intersection->data<<endl;  // Give data at which 'slow' is caught by 'fast'
    Node* slow = head;  // slow is intialized to be a head

    while(slow != intersection){  // Run loop until slow does not meet intersection
        slow = slow->next;  // Move slow forward
        intersection = intersection->next;  // Move intersection forward as well
    }
    return slow;
}

void removeLoop(Node* &head){
    if(head == NULL){
        return;
    }

    Node* startingOfLoop = getStartingNode(head); // Gets me the starting Node 
    Node* temp = startingOfLoop;
    
    while(temp->next != startingOfLoop){  // Tabta chalna hai jabtak temp ka agla node startingOfLoop wala node nahi hai
        temp = temp->next;
    }
    temp->next = NULL;  // Loop se bahar aagaye means StartingOfLoop wala node mil gaya toh temp ko NULL par point karwado startingOfLoop wala node par point mat karna
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