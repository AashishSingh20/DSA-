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

void reverseLL(Node* &head){
    // If there is no node in the LL or LL only has one node
    if(head == NULL || head->next == NULL){
        return;
    }

    // In case of 2 or more nodes in LL use below code
    Node* prev = NULL;  // Initially prev NULL hai
    Node* curr = head;  // 'curr' is pointing to head then it keeps on moving

    while(curr != NULL){  // Jabtak 'curr' NULL nahi ho jata tabtak continue the looping+
       Node* forward = curr->next;  // 'forward' is at the next node of 'curr'
       curr->next = prev;   // Now that connection of curr is safe due to forward we can safely point 'curr' to its previous node
       prev = curr;  // Now point 'prev' to 'curr'
       curr = forward;  // and move 'curr' to 'forward' as well (in the next iteration forward will again come after curr and so on)
    }
    head = prev;  // Now new head will be the last element of the LL as LL is reversed and 'prev' is pointer towards that last node
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