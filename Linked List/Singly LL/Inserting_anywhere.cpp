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
            this->data = data;  // data
            this->next = NULL;  // Next pointer ko NULL Par Point kar dega
        }
};

void headInsert(Node* &head, Node* &tail, int data){  // By reference le rahe hai taki copy na banana pade saari changes in original LL
    // New Node creating
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    // inserting at head
    temp->next = head;
    head = temp;
}

void tailInsert(Node* &head, Node* &tail, int data){  // By reference le rahe hai taki copy na banana pade saari changes in original LL
// New Node creating and inserting at Tail
Node* temp = new Node(data);

    if (head == NULL) {  // This states that if LL is empty then return 
        head = temp;  // If the list is empty this makes Head point to the new Node
        tail = temp;  // Since only one node so the new node is also the tail node
        return;  
    }

    tail->next = temp;   // Tail ka pointer ab temp ko pointer karega
    tail = temp;   // Tail to update karke temp ko dedo abd new tail is temp
}

void Insert(Node* &head, Node* &tail, int position, int data){  // By reference le rahe hai taki copy na banana pade saari changes in original LL
    
    if (position == 1) {   // Agar user ne bola 1st position par daalo then Insert at Head wale operation karo
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
        return;
    }

    Node* temp = head;  // temp points to head, used to traverse the linked list without changing head
    int count = 1;  // It is used to find the correct place to insert a new Node

    while(count < position-1 && temp->next != NULL){  // Loop until count reaches the correct position and will work only untill previous element does not point to NULL
        temp = temp->next;  // Used to Move temp to the next nodes until we reaches the node after which we have to insert the new Node
        count++;
    }

// Inserting at Last Position
    if(temp == tail){  // Agar current node(temp) is tail then use tailInsert
        tailInsert(head,tail,data);
        return;
    }

    //Creating a Node for d
    Node* nodeToInsert = new Node(data);  // Creating a new node which we hae to Insert in the LL
    nodeToInsert->next = temp->next;  // Previous node ka address jo next node ko point kar raha hai woh new node ko dedo
    temp->next = nodeToInsert;  // prevoius node ko ab new node ka address de do 
}

void print(Node* &head){  // Same as as above for taking by reference
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

// Head pointed to node1 and tail is created to find tail and insert at tail
    Node* head = NULL;
    Node* tail = NULL;

// Insertion into the LL
    int n,ele;
    cout<<"Enter How Many Elemets in the LL: ";
    cin>>n;

    cout<<"Enter LL Elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        tailInsert(head,tail,ele); // Inserts elements in the LL from Behind
    }

    int position,data;
    cout<<"Enter position you want to insert in: ";
    cin>>position;
    cout<<"Enter Data you want to Insert in Between: ";
    cin>>data;

    Insert(head,tail,position,data);  // Insert in Between
    cout<<"After Inserting New Element in Between: ";
    print(head);
}