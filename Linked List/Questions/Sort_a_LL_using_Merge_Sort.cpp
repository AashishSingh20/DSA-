#include<iostream>
#include<algorithm>
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

Node* split(Node* head){
    Node* fast = head;  //
    Node* slow = head;

    // Move fast pointer 2 steps and slow pointer 1 step until fast reaches end
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        if(fast != NULL){
            slow = slow->next;
        }
    }

    // Split the list into 2 Halves
    Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Merge 2 sorted Linked List
Node* merge(Node* first, Node* second){
    if(first == NULL) return second;
    if(second == NULL) return first;

    // Compare which Node's data is smaller 
    if(first->data < second->data){   // Agar pehle node ka data is smaller than 2nd node data
        first->next = merge(first->next, second);  // first ka next node 
        return first;
    }
    else{
        second->next = merge(first, second->next);
        return second;
    }
}

Node* mergeSortUnsorted(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* second = split(head);

    head = mergeSortUnsorted(head);
    second = mergeSortUnsorted(second);

    return merge(head, second);
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
    
    head = mergeSortUnsorted(head);
    print(head);
}