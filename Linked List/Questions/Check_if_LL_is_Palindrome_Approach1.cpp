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
    if(tail == NULL){
        head = temp;
        tail = temp;
        return;
    }
    
    tail->next = temp;
    tail = temp;
}

void print(Node* &head){
    if(head == NULL){
        cout<<"List is Empty.";
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool isPalindrome(Node* head){
    if(head == NULL){
        return false;
    }
    Node* newHead = NULL;

    Node* curr = head;
    while(curr != NULL){
        Node* newNode = new Node(curr->data);
        newNode->next = newHead;
        newHead = newNode;
        curr = curr->next;
    }

    Node* a = head;
    Node* b = newHead;

    while(a != NULL){
        if(a->data != b->data){
            return false;
        }
        else{
            a = a->next;
            b = b->next;
        }
    }
    return true;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    int n,ele;
    cout<<"Enter number of Nodes in LL1: ";
    cin>>n;
    
    cout<<"Enter LL1 Elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        tailInsert(head,tail,ele);
    }

    if(isPalindrome(head)){
        cout<<"Linked List is Palindrome. ";
    }
    else{
        cout<<"linked List is not a Palindrome. ";
    }
}