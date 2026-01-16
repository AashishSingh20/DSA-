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
    if(head == NULL || head->next == NULL){
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

bool isPalindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }

    // Step-1 Finding Mid
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow;

    //Step - 2 Reverse LL after mid
    Node* temp = mid->next;
    mid->next = reverse(temp);
    
    // Step-3 Compare both halves
    Node* head1 = head;
    Node* head2 = mid->next;
    while(head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        else{
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return true;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    int n,ele;
    cout<<"Enter number of Nodes in LL1: ";
    cin>>n;
    
    cout<<"Enter LL1 Elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        tailInsert(head,tail,ele);
    }

    if(isPalindrome(head)){
        cout<<"Linked List is Palindrome. ";
    }
    else{
        cout<<"Linked List is not a Palindrome. ";
    }
}