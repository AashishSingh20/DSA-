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

// void removeDuplicates(Node* &head){   // Method 1
//     if(head == NULL){
//         return;
//     }

//     Node* first = head;  // Points 1st node of duplicate data
//     Node* last = head;  // Points last node of the same duplicate data

//     while(last != NULL){
//         if(first->data == last->data){
//             last = last->next;
//         }
//         else{
//             first->next = last;
//             first = last;
//             last = last->next;
//         }
//         first->next = NULL;
//     }
// }

Node* uniqueSorted(Node* head){    // Method 2
    if(head == NULL){   // agar head NULL hoga toh return NULL 
        return NULL;
    }

    Node* curr = head;  // 'curr' Node banao joh head ko point karega initially
    
    while(curr != NULL){  // Loop until 'curr' NULL par nahi pohach jata
        if((curr->next != NULL) && curr->data == curr->next->data){  // agar 'curr' ka next node NULL nahi hai and 'curr' ka data uske ke baad ke data ke barabar hai toh aage badho
            Node* next_next = curr->next->next;  // 'next_next' pointer banao joh 'curr' ke badke baad waale node ko point kare
            Node* nodeToDelete = curr->next;  // 'nodeToDelete' ek pointer banao joh curr ke just baad wale element ko point kare
            delete(nodeToDelete);  // since same data in next nodes a rahe hai toh 'nodeToDelete' ka joh node hai usko delete karte jao to free Memory
            curr->next = next_next;  // 'curr' ke next ko next_next(matlab ek kadam aur aage) par point kardo
        }
        else{
            curr = curr->next;  // Agar if condition is not fulfilled means node duplicate nahi hai so 'curr' ko aage badhate jao jabtak phirse duplicate nodes na milne lage
        }
    }
    return head;   // head ko return kardo  
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
    
    head = uniqueSorted(head);
    print(head);
}