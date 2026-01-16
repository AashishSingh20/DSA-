#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    public:
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

void insertAtTail(Node* &head, Node* &tail,int data){
    Node* temp = new Node(data);
    if(head == NULL){     
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void reverseLL(Node* &head){
    // If there is no node in the LL or LL only has one node
    if(head == NULL || head->next == NULL){
        return;
    }

    // In case of 2 or more nodes in LL use below code
    Node* curr = head;  // 'curr' is pointing to head then it keeps on moving
    Node* temp = NULL;  // Initially temp is NULL, temp is pointing towards the previous element

    while(curr != NULL){  // Jabtak 'curr' NULL nahi ho jata tabtak continue the looping
        // Swap kardo curr and previous of Doubly LL
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // move to next node which is prev now
        curr = curr->prev;
    }
    head = temp->prev;  // update head;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int n,ele;
    cout<<"Enter number of nodes in LL: ";
    cin>>n;

    if(n==0){
        cout<<"Linked List is Empty";
        return 0;
    }

    if(n==1){
        cout<<"Reverse is Same as Original";
        return 0;
    }
    
    cout<<"Data members: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        insertAtTail(head,tail,ele);
    }

    reverseLL(head);
    cout<<"Reverse: ";
    print(head);
}