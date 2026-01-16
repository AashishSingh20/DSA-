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

// It will return head of the reversed list
Node* reverse(Node* &head){
    if(head == NULL || head->next == NULL){  // If list is empty or only one node is present then return head of the list
        return head;
    }

    Node* chhotaHead = reverse(head->next);  // chhotaHead banao aur reverse function ko call
    head->next->next = head;
    head->next = NULL;
    return chhotaHead;
}

void reverseLL(Node* &head){
    head = reverse(head);  // reverse mein joh head aayega usko hi head banadena aur aage bhej dena print e liye 
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