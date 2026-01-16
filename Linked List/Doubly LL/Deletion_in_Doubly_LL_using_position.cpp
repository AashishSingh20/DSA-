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
            int val = this->data;  // val data in LL ko point kar raha hai
            next = NULL;  // Jab Destructor call hoga toh woh next ko NULL ko point karwa dega
            cout<<"Memory Free for Node with Data: "<<val<<endl; // Prints which data is deleted
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

void deleteNode(Node* &head, Node* &tail, int position){
    if(head == NULL){  // List os Empty
        return;
    }
// Deletion of 1st Node
    if(position == 1){
        Node* temp = head;
        head = temp->next; // Head ko aage badha do
        if(head != NULL){ // Agar aage badhane ke baad head NULL nahi hua means there is not just 1 element in LL
            head->prev = NULL;  // Ab head ke prev ko NULL opar point kardo jo previous ko point kar raha tha
        }
        else{
            tail = NULL; // Agar next head NULL hua toh tail and head both becomes NULL
        }

        temp->next = NULL;  // Ab jo temp hai matlab pehle wala head usko NULL par point karwado
        delete temp;  // Now that temp is completely isolated delete it
        return; 
    }

    else{
        Node* curr = head;  // curr ko starting mein head par rakho then traverse it
        int count = 1; 

        while(count < position && curr != NULL){  // Jabtak curr apni jagah par na pohach jaye aur jabtak curr NULL nahi hai keep on going
            curr = curr->next;  // curr next element ko point karke aage badhte jaa raha hai
            count++;  // Har bar count badhega jab curr aage badega
        }

        if(curr == NULL){  // agar 'curr' NULL ho gaya toh return kardo means user ne joh position de hai woh list mein exist nahi karti
            return;
        }

// Deletion of Tail Node
        if(curr == tail){  // Agar curr tail node nikla aur usko delete karna hai then whis will be used 
            tail = tail->prev;  // tail to previous wale node par shift kardo ab previous node is tail node
            tail->next = NULL;  // ab previous node tail ban gaya to ab usko NULL par point karwado
            curr->prev = NULL;  // Pehle wale tal node means 'curr' ko NULL kardo taki uska sab relation khatam ho jaye
            delete curr;  // Ab it is safe to delete 'curr' node
            return;
        }

// Deletion of Middle Node
        curr->prev->next = curr->next;  // 'curr' ko delete karna hai so usse pehle wale node ko uske baad wale node par point karwado
        curr->next->prev = curr->prev;  // Ab 'curr' ke baad ke node ko 'curr' ke pehle wale node par point karwa do

        curr->prev = NULL;  // Curr element ke aage wale address ko NULL kardo taki 'curr' ke saare relations tut jaye
        curr->next = NULL;  // Same use next pointer ko bhi NULL point karwado
        delete curr;   // Now it is Safe to Delete curr
    } 
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

    int position;
    cout<<"Enter Position you want to Delete: ";
    cin>>position;
    deleteNode(head,tail,position);

    cout<<"After Deletion: ";
    print(head);

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
}