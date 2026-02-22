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

Node* add(Node* first, Node* second){
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;
    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        int val2 = 0;
        if(first != NULL) val1 = first->data;
        if(second != NULL) val2 = second->data;

        int sum = carry + val1 + val2;
        int digit = sum%10;

        // Creates new Node and stores digit in ans LL
        tailInsert(ansHead,ansTail,digit);
        carry = sum/10;
        if(first != NULL)   first = first->next;
        if(second != NULL)  second = second->next;
    }
    return ansHead;
}

Node* addTwoLists(Node* first, Node* second){
    // Step 1: Reverse both LL
    first = reverse(first);
    second = reverse(second);

    // Step 2: Add Both LL
    Node* ans = add(first , second);

    // Step 3: Reverse the output
    ans = reverse(ans);

    return ans;

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
    
    Node* head = addTwoLists(first,second);
    print(head);
}