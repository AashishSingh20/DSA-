#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    public: 
    // Constructor
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
    
    // Destructor
        ~Node(){
        }
};

void insertAtHead(Node* &head,Node* &tail, int data){
    Node* temp = new Node(data);
    if(head == NULL){     
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

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

void insertAtMid(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head,tail,data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1 && temp->next != NULL){
        temp = temp->next;
        count++;
    }

    if(temp == tail){
        insertAtTail(head,tail,data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}


// Traversing and Printing a Linked List
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
    cout<<"Enter How Many Elemets in the LL: ";
    cin>>n;

    cout<<"Enter LL Elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        // insertAtHead(head,tail,data);
        insertAtTail(head,tail,ele);
    }
    // cout<<"After Head Insertion: ";
    // cout<<"After Tail Insertion: ";

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    int data,position;
    cout<<"Enter Data: ";
    cin>>data;
    cout<<"Enter Position you want to Insert in: ";
    cin>>position;
    insertAtMid(head,tail,position,data);

    cout<<"After Insertion: ";
    print(head);

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
}