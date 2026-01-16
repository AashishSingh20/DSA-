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

Node* solve(Node* first, Node* second){
    // if only one Node is present in the LL
    if(first->next == NULL){  // Agar 1 hi elemt hai toh uska next1 nukle hi nahi aur woh loop mein jayega hi nahi isliey ye case dena padega
        first->next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1->next; 
    Node* curr2 = second;

    while(next1 != NULL && curr2 != NULL){  // Loop karo jabtak next1 matlab jabtak 1st LL ke last element par na pohach jaye and 2nd list NULL na ho jaye
        if(curr2->data >= curr1->data && curr2->data <= next1->data){  // agar curr2 ka ka data lies between curr1 and next1
            // Add Node from second to first
            curr1->next = curr2;   // curr1 ke next par curr2 ko point karwado
            Node* next2 = curr2->next;
            curr2->next = next1;
            // Update Pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }   
    }
    return first;
}

Node* mergeLL(Node* first, Node* second){
    if(first == NULL){  
        return second;
    }
    if(second == NULL){
        return first;
    }

    if(first->data <= second->data){  // first LL usko banao jiska first data smaller ho
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
}

int main(){
    Node* head = NULL;
    Node* first = NULL;
    Node* tail1 = NULL;
    Node* second = NULL;
    Node* tail2 = NULL;
    
    int n1,ele;
    cout<<"Enter number of Nodes in LL1: ";
    cin>>n1;

    int n2;
    cout<<"Enter number of Nodes in LL2: ";
    cin>>n2;
    
    cout<<"Enter LL1 Elements: ";
    for(int i=0;i<n1;i++){
        cin>>ele;
        tailInsert(first,tail1,ele);
    }

    cout<<"Enter LL2 Elements: ";
    for(int i=0;i<n2;i++){
        cin>>ele;
        tailInsert(second,tail2,ele);
    }

    print(first);
    print(second);

    head = mergeLL(first,second);
    print(head);
}