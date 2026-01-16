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
    if(tail == NULL){
        head = temp;
        tail = temp;
        return;
    }
    
    tail->next = temp;
    tail = temp;
}

void print(Node* &head){
    if(head == NULL){
        cout<<"List is Empty.";
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverse(Node* head){
    if(head == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

Node* addition(Node* first, Node* second){   
    first = reverse(first);
    second = reverse(second);

    Node* curr1 = first;   // Points to the first Node of first LL
    Node* curr2 = second;  // Points to the first Node of second LL
    Node* prev = NULL;  // Tracks last processed Node of LL
    int carry = 0;   // Initially carry is 0

    while(curr1 != NULL || curr2 != NULL){  // Loop until either curr1 becomes NULL or curr2 becomes NULL(Ek bhi agar NULL nahi hai toh Loop Chalega)
        int sum = carry;   // sum ke ander carry ki value hogi joh initally 0 hai 
        if(curr1 != NULL) sum += curr1->data;  // Agar curr1 ka data NULL nahi hai toh usko sum mein daldo
        if(curr2 != NULL) sum += curr2->data;  // And agar curr2 ka data bhi NULL nahi hai toh usko sum mein daldo

        carry = sum/10;  // Isse Carry nikal jayega (Eg: sum = 12 puts 1 in carry)
        sum = sum%10;  // sum ka modulus nakalo aur usse sum mein hi daldo(Eg:- sum = 12 put 2 in sum)

        if(curr1 != NULL){   // Agar curr1 NULL nahi hua hai toh 
            curr1->data = sum;  // curr1 ke data ko update kardo aur usmein sum ki value put kardo
            prev = curr1;  // prev ko curr1 par le aao
            curr1 = curr1->next;  // curr1 ko ko aage shift kardo
        }
        else{
            prev->next = new Node(sum);  // Agar curr1 NULL ho gay toh prev ke baad ek naya node banao aur usmein sum ki value put karte jao
            prev = prev->next;  // prev ko aage badhate jao
        }

        if(curr2 != NULL){   // Agar curr2 NULL nahi hai toh 
            curr2 = curr2->next;  // curr2 k aage badhate jao iski value sum mein add hoti rahengi
        }

    }

    if(carry != 0){   // agar sab sum hone ke baad carry baccha hai toh 
        prev->next = new Node(carry);   // naya node banake prev ke next par attach kardo
    }

    return reverse(first);
}

int main(){
    Node* first = NULL;
    Node* firstTail = NULL;
    Node* second = NULL;
    Node* secondTail = NULL;
    
    int n1,ele;
    cout<<"Enter number of Nodes in LL1: ";
    cin>>n1;
    
    int n2;
    cout<<"Enter number of Nodes in LL2: ";
    cin>>n2;
    
    cout<<"Enter LL1 Elements: ";
    for(int i=0;i<n1;i++){
        cin>>ele;
        tailInsert(first,firstTail,ele);
    }
    
    cout<<"Enter LL2 Elements: ";
    for(int i=0;i<n2;i++){
        cin>>ele;
        tailInsert(second,secondTail,ele);
    }
    
    Node* head = addition(first,second);
    print(head);
}