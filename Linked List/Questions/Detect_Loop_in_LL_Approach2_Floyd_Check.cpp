#include<iostream>
using namespace std;


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

void insertNode(Node* &tail, int element, int data){  // element is the node after which we want to insert the new node and data reprsents the new node

    // List is Empty
    if(tail == NULL){  
        Node* newNode = new Node(data);  // Naya node create karo
        tail = newNode;  // Tail new Node ko assign karo
        newNode->next = newNode;  // ab 'NewNode' apne aap ko hi point karega because it is circular LL and only one node is there
    }
    else{
    // Non Empty List  
    // Assuming that atleast one element is present in the Linked List
        Node* curr = tail;
        
        do{
            if(curr->data == element){  // If element is found break the searching 
                break;
            }
            curr = curr->next;  // shift 'curr' until element is not found
        }
        while(curr != tail);  // loop until curr does not reach tail  

        // Element is found and 'curr' is representing the element node
        Node* temp = new Node(data);  // New node banao jo list mein insert karna hai
        temp->next = curr->next;  // 'curr' jisko point kar raha hai woh 'temp' ko point karne ke liye dedo
        curr->next = temp;  // ab 'curr' apne baad wale node ko point karega nahi dusre node ko
    }
}

void print(Node* tail){  
    Node* temp = tail;
    if(tail == NULL){
        cout<<"List is empty";
        return;
    }

    do{ 
        cout<<tail->data<<" ";  
        tail = tail->next;  
    }
    while(tail != temp);  
    cout<<endl;
}

Node* isCircularLL(Node* &tail){  // Here we have used Circular List so it will be always true put this function in Normal List it will show not a circular Linked List
    if(tail == NULL){
        return NULL;
    }
    Node* slow = tail;
    Node* fast = tail;
    if(tail->next == NULL){
        return NULL;
    }
    while(fast != NULL && fast->next != NULL){  // Loop until 'fast' wala node is not NULL or 'fast' ka next node is not NULL
        fast = fast->next->next;  // 'fast' ko 2 - 2 step badhate jao
        slow = slow->next;  // 'slow' ko 1 - 1 step badhate jao
        if(slow == fast){  // Jab 'fast' catches 'slow' that means loop is present
            cout<<"Fast catches slow at: "<<slow->data<<endl;  // Give data at which 'slow' is caught by 'fast'
            return slow;
        }
    }
    return NULL;
}

int main(){
    Node* tail = NULL;

    insertNode(tail,5,3); 
    print(tail);

    insertNode(tail,3,5); 
    print(tail);

    insertNode(tail,5,7); 
    print(tail);

    insertNode(tail,3,4);
    print(tail);

    insertNode(tail,5,6);
    print(tail);

    if(isCircularLL(tail)){
        cout<<"List has a Loop.";
    }
    else{
        cout<<"List does not have a Loop.";
    }
}

