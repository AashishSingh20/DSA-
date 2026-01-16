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

        ~Node(){
            int val = this->data;
            next = NULL;
            cout<<"Node to be Deleted contains data: "<<val<<endl;
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

void print(Node* tail){  // here we are taking tail by value so a copy will be created if we take by reference then there will be changes in tail of original LL
    Node* temp = tail;
    if(tail == NULL){
        cout<<"List is empty";
        return;
    }

    do{   // do while loop atleast prints once before checking conditions (so if the list only has one node while will not work but do will print the data)
        cout<<tail->data<<" ";  // Prints data at tail 
        tail = tail->next;  // Move tail forward
    }
    while(tail != temp);  // Abhi temp hi tail hai toh loop tabtak chalana hai jabtak next bhi temp par na aajaye
    cout<<endl;
}

int main(){
    Node* tail = NULL;

    insertNode(tail,5,3);  // Abhi List empty hai toh no element so it will just insert 3 in LL
    print(tail);

    insertNode(tail,3,5);  // Now '3' is there in LL so this tells insert '5' after '3'
    print(tail);

    insertNode(tail,5,7);  // Now '3 & 5' is there in LL so this tells insert '7' after '5'
    print(tail);

    insertNode(tail,3,4);
    print(tail);

    insertNode(tail,5,6);
    print(tail);
}