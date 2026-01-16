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

bool isCircularList(Node* &tail){
    if(tail == NULL){  // Agr tail NULL par hai means no nodes consider it as the list is circular
        return true;
    }

    Node* temp = tail->next;  // make temp and place it next to tail 
    while(temp != NULL && temp != tail){  // loop until temp is not NULL and temp does not again come back to tail again 
        temp = temp->next;  // temp ko aage badhate jao
        if(temp == NULL) return false;  // agar temp NULL par pohach gaya means it is not circular as not node point to NULL in circular LL
        if(temp == tail) return true;  // Agar temp traverse karke phirse tail par pohach gaya measns it is circular  
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

    if(isCircularList(tail)){
        cout<<"It is a Circular List.";
    }
    else{
        cout<<"It is not a Circular List.";
    }
}