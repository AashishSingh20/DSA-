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

Node* findMiddle(Node* head){
    if(head == NULL || head->next == NULL){  // If there are no nodes or single node return head
        return head;
    }
    
    if(head->next->next == NULL){  // If there are 2 nodes then middle is the 2nd node
        return head->next;
    }
    
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL){
        fast = fast->next;  // Fast k ek baar aage badhao phir 2nd time aage badhane se pehle check karo ki kahi wo NULL toh nahi ho gaya
        if(fast != NULL){
            fast = fast->next;  // If not NULL then again move forward(agar hum 2nd time aage badhane se pehle check nahi karenge toh error aayega)
        }
        slow = slow->next;
    }
    return slow;
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

    Node* mid = findMiddle(head);
    cout<<"Middle Node of LL: "<<mid->data<<endl;
}