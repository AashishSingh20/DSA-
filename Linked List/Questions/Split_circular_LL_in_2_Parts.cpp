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

void insertNode(Node* &head, int element, int data){ 

    if(head == NULL){  
        Node* newNode = new Node(data); 
        head = newNode; 
        newNode->next = newNode;
    }
    else{
        Node* curr = head;
        
        do{
            if(curr->data == element){ 
                break;
            }
            curr = curr->next; 
        }
        while(curr != head); 

        Node* temp = new Node(data); 
        temp->next = curr->next; 
        curr->next = temp; 
    }
}

void print(Node* &head){
    if(head == NULL){
        cout<<"List is Empty.";
        return;
    }
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);

    cout<<endl;
}

Node* findMiddle(Node* head){
    if(head == NULL){
        cout<<"Not a Circular LL";
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void splitCircularLL(Node* head){
    if(head == NULL || head->next == head) {  // Agar head ke paas element nahi hai ya head ka agla element head hai means single circular nodes(Split not possible)
        cout << "Cannot split "<<endl;  
        return;  // return kardo
    }

    Node* head1 = head;    // head1 ko head par point karo
    Node* mid = findMiddle(head);  // Isse middle pata chal jayega usko mid mein daaldo
    Node* head2 = mid->next;  // head2 ko mid ke agle node par set kardo 

    mid->next = head1;  // ab mid ke next ko head 21 se jodh do(split of 1st half is done)

    Node* temp = head2;  // temp ko head2 par as a pointer banao 
    while(temp->next != head){  // temp ko aage badhate jao until temp ka aagla node head na ho
        temp = temp->next;
    }

    temp->next = head2;  // agar temp ka agla node head hai toh temp ke next ko head2 par point kardo (split of 2nd half complete)

    cout<<"List 1: ";
    print(head1);

    cout<<"List 2: ";
    print(head2);
}

int main(){
    Node* head = NULL;

    insertNode(head,5,10); 
    insertNode(head,10,20); 
    insertNode(head,20,30);  
    insertNode(head,30,40);
    insertNode(head,40,50);
    insertNode(head,50,60);
    print(head);

    Node* mid = findMiddle(head);
    cout<<"Mid Element of the Circular LL is: "<<mid->data<<endl;
    
    splitCircularLL(head);  // Gives split of circular LL
}