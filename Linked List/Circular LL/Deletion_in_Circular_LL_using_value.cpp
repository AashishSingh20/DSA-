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
void insertNode(Node* &tail, int element, int data){ 

    // List is Empty
    if(tail == NULL){  
        Node* newNode = new Node(data); 
        tail = newNode;
        newNode->next = newNode; 
    }
    else{
    // Non Empty List  
    // Assuming that atleast one element is present in the Linked List
        Node* curr = tail;
        
        do{
            if(curr->data == element){ 
                break;
            }
            curr = curr->next; 
        }
        while(curr != tail);

        Node* temp = new Node(data);
        temp->next = curr->next; 
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    // Empty List
    if(tail == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    
    // List is not Empty
    // Checking whether data is present or not
    Node* prev = tail;  // Prev element is tail 
    Node* curr = prev->next;   // 'curr' will point to the next node of 'prev' as it is forward 
    bool found = false;

    do{  // This ensures atleast one iteration of LL is done
        if(curr->data == value){  // Agar curr position par jo data hai woh value se match hogaya toh return true and stop this loop
            found = true;
            break;
        }
        prev = curr;  // 'prev' 'curr' ka pakad raha hai
        curr = curr->next;  // curr aage jaate jaa raha hai
    }while(curr != tail->next);  // loop tabtak chalana jabtak curr phir same position par na aajaye

    if(!found){  // if value given by user is not found then return this statement
        cout<<"Data given is not on the List";
    }

    // Completed checking whether data is there or not, now set 'curr' to reach the value we want to delete
    while(curr->data != value){    // Loop until 'curr' ka joh data hai woh value ke barabar nahi aata
        prev = curr;  // prev ko 'curr' ke barabar karte jao 
        curr = curr->next;  // Aur 'curr' ko bhi aage bhadate jao
    }

    prev->next = curr->next;   // 'prev' ke aage address mein 'curr' ke next element ka address dedo
    if(curr == prev) {  // If 'curr' and 'prev both are same means there is only one element in the list
        tail = NULL;  // if this 1 element is deleted from the list then tail will be NULL means list is empty
    }
    if(curr == tail){  // Agar 'curr' node is tail then shift tail to the 'prev' node 
        tail = prev;  // 
    }
    curr->next = NULL;  // now make 'curr' node to point to null before deleting from memory
    delete curr;  // Now we can Safely delete 'curr'
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
    insertNode(tail,3,5);
    insertNode(tail,5,7);
    insertNode(tail,3,4);
    insertNode(tail,5,6);
    print(tail);
    cout<<"Tail: "<<tail->data<<endl;
    
    int data;
    cout<<"Enter data to be deleted from the LL: ";
    cin>>data;
    deleteNode(tail,data);
    print(tail);
    cout<<"Tail: "<<tail->data<<endl;
}