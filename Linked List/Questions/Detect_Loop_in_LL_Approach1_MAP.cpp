#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    public:
        Node(int data){
            this->data = data;
            this->next = next;
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

bool detectLoop(Node* &tail){
    if(tail == NULL){
        return false;
    }

    map<Node*, bool> visited;  // A map is created to mak every node visited once as visited if the traversal again comes to any visited node then it has a loop
    Node* temp = tail;

    while(temp != NULL){
        if(visited[temp] == true){  // Agar koi node pehle se hi visited(true) marked hai means it has a loop
            return true;
        }

        visited[temp] = true;  // Temp jis nodes par jayega usko visited(true) mark kardena
        temp = temp->next;
    }
    return false;
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

    if(detectLoop(tail)){
        cout<<"List has a Loop.";
    }
    else{
        cout<<"List does not have a Loop.";
    }
}