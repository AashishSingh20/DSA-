#include<iostream>
using namespace std;


class Node{
// Data members of class Node
    public:
        int data;
        Node* next;  

// Constructor
    public:
        Node(int data){
            this->data = data;
            this->next = NULL; 
        }
};

void tailInsert(Node* &head, Node* &tail, int data){  

Node* temp = new Node(data);

    if (head == NULL) { 
        head = temp;  
        tail = temp;  
        return;  
    }

    tail->next = temp; 
    tail = temp; 
}

void print(Node* &head){  // Same as as above for taking by reference
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* uniqueUnSorted(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* curr = temp->next;
        Node* prev = temp;
        while(curr != NULL){
            if(temp->data == curr->data){
                Node* nodeToDelete = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete(nodeToDelete);
            }
            else{
                prev = curr;
                curr = curr->next;   
            }
        }
        temp = temp->next;
    }
    return head;
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
        tailInsert(head,tail,ele); // Inserts elements in the LL from Behind
    }
    
    head = uniqueUnSorted(head);
    print(head);
}