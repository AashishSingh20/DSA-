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

void tailInsert(Node* &head, Node* &tail, int data){ 
    Node* temp = new Node(data);

    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    
    tail->next = temp;
    tail = temp;
}

void reverse(Node* &head, Node* &curr, Node* &prev){
    if(curr == NULL){  // Agar 'curr' NULL par pohach gaya then stop
        head = prev;
        return;
    }
    else{
        Node* forward = curr->next;  // 'forward' is moving forward with each call
        reverse(head, forward, curr); // Ab next call mein 'curr' 'forward' ki jagah aa jayega aur 'prev' 'curr' ki jagah(New curr will be forward and new prev will be the curr)
        curr->next = prev;  // Ab Arrow ulta hota jayega with each call
    }
}

void reverseLL(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return;
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
        tailInsert(head,tail,ele);
    }

    reverseLL(head);
    cout<<"Reverse: ";
    print(head);
}