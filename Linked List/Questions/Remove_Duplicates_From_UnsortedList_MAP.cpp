#include<iostream>
#include<map>
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
    if(head == NULL){   // agar head NULL hoga toh return NULL 
        return NULL;
    }
    
    map<int, bool> visited;   // Values ko check karna hai naki nodes ko isliye using int and not Node*
    Node* curr = head;  
    Node* prev = NULL;
    while(curr != NULL){
        if(visited[curr->data]){  // Agar curr ka data visit aur woh true nahi hai then use this
            Node* nodeToDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(nodeToDelete);
        }
        else{
            visited[curr->data] = true;  // First time value mil raha hai toh mark it as true
            prev = curr;
            curr = curr->next;
        }
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