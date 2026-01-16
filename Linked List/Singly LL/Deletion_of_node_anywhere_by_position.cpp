#include<iostream>
#include<vector>
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

void tailInsert(Node* &head,Node* &tail, int data){  // Sirf elements piche se aad ho isliye use kiya hai
    Node* temp = new Node(data);
    
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = tail->next;
}

// Deleting a Node
void deleteNode(Node* &head, Node* &tail, int position){
    if(head == NULL){  // List is Empty
        return;
    }

    //Deleting start Node/Head Node
    if(position == 1){
        Node* temp = head;  // temp pointer banao joh head ko point kare
        head = head->next;  // head ko shift kardo aage 
        
        if(head == NULL){  // Agar head mein hi kuch nahi hai matlab list is empty then tail will also be NULL
            tail = NULL;
        }

        temp->next = NULL; // Before deleting temp joh next element ko point kar raha tha usko NULL point karwado taki 2 nodes same location ko access na kare
        delete temp;   // previous head jisko temp point kar raha hai usko delete kardo
    }
    else{
        //Deleting any Middle Node or Last Node
        Node* curr = head;   // Current Pointer Initially 1st position par hoga
        Node* prev = NULL;  // prev Pointer NULL hoga initially kyuki woh exist hi nahi karta starting mein
        int count = 1;
        
        while(count < position && curr != NULL){   // Jabatak count position se barabar nahi aata tabtak loop chalao
            prev = curr;  // Initially prev aur curr ek hi jagah honge phir curr ke sath ek position piche chalte jayega
            curr = curr->next;  // curr pointer ko aage badhate jao jabtak position par na pohach jao
            count++;  // count badhate jao
        }
        if(curr == NULL){
            return;
        }

        if(curr == tail){
            tail = prev;  // Since curr node needs to be deleted prev node ko tail assign kardo
            prev->next = NULL;  // agar Last node is tail aur usse delete karna hai toh previous wale ko NULL ko point karna hoga
            delete curr;  // Ab curr ko delete mardo 
            return;
        }
        prev->next = curr->next;  // curr jisko point kar raha tha usko prev ko dedo
        delete curr;
    }
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
    cout<<"Enter How Many Elemets in the LL: ";
    cin>>n;

    cout<<"Enter LL Elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        tailInsert(head,tail,ele);
    }

    int position;
    cout<<"Enter Position You want to Delete: ";
    cin>>position;

    cout<<"Before Deletion: ";
    print(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    
    deleteNode(head,tail,position);
    cout<<"After Deletion: ";
    print(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
}