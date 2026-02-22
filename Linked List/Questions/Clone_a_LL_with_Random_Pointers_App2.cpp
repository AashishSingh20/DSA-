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

Node* copyRandomList(Node* head) {
    // step 1:- Create a Clone List
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    
    Node* temp = head;
    while(temp != NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }
    
    // Step 2:- CloneNodes ko original List mein add karo
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    
    while(originalNode != NULL && cloneNode != NULL){
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;
        
        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }
    
    // Step 3:- Random Pointers ko copy karo in cloeNode
    temp = head;
    while(temp != NULL){
        if(temp->next != NULL){
            if(temp->random != NULL){
                temp->next->random = temp->random->next;
            }
            else{
                temp->next->random = NULL;
            }
        }
        temp = temp->next->next;  // Agli originalLL ke node par pohachna hai toh temp ko 2 baar aage badhana hoga kyuki second node is of cloneLL
    }
    
    //Step 4:- Revert Step2
    originalNode = head;
    cloneNode = cloneHead;
    
    while(originalNode != NULL){
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        
        if(originalNode != NULL){
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }
    
    // Step 5:- Return ans;
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
    head = copyRandomList(head);
    print(head);
}