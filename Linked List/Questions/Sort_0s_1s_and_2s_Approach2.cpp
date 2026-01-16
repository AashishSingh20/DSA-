#include<iostream>
#include<algorithm>
using namespace std;


class Node{
// Data members of class Node
    public:
        int data;
        Node* next;  

// Constructor
    public:
        Node(int data){
            this->data = data;
            this->next = NULL; 
        }
};

void tailInsert(Node* &head, Node* &tail, int data){  

Node* temp = new Node(data);

    if (head == NULL) { 
        head = temp;  
        tail = temp;  
        return;  
    }

    tail->next = temp; 
    tail = temp; 
}

void print(Node* &head){  // Same as as above for taking by reference
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* Sort012(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    // Created Separate List's of 0's,1's and 2's
    while(curr != NULL){
        Node* nextNode = curr->next;  // save next
        curr->next = NULL;   // curr wale ko detach kardo  
        int value = curr->data;
        if(value == 0){
            zeroTail->next = curr;  // Initially 0 wale LL ka tail and head same hai agar 0 mila LL mein toh tail ke next mein curr daldo
            zeroTail = zeroTail->next;  // 0 wale LL mein uska zeroTail aage badhado
        }
        else if(value == 1){
            oneTail->next = curr;   // same as above
            oneTail = oneTail->next;
        }
        else if(value == 2){
            twoTail->next = curr;  // same as above
            twoTail = twoTail->next;
        }
        curr = nextNode;
    }

    // Now we are merging the sublists of 0's, 1's and 2's
    if(oneHead->next != NULL){   // Agar oneHead is not NULL then 
        zeroTail->next = oneHead->next;  // 0 ke tail se 1 ka head connect kardo
        oneTail->next = twoHead->next;  //  And 1 ke tail se two ka head connect kardo
    }
    else{
        zeroTail->next = twoHead->next;  // agar 1 ka hea NULL hai means there is no one in LL so 0 ke tail se 2 ka head connect kardo
    }
    
    twoTail->next = NULL;  // 2 ke tail ko NULL par point karwado since it is the last node
    head = zeroHead->next;  // head mein zerohead ki next value ko point karwado

    delete zeroHead;  // ZeroHead, oneHead and twoHead mein -1 pada hai usse khali kardo
    delete oneHead;
    delete twoHead;

    return head;    
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int n,ele;
    cout<<"Enter How Many Elemets in the LL: ";
    cin>>n;

    cout<<"Enter LL Elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        tailInsert(head,tail,ele); // Inserts elements in the LL from Behind
    }
    
    head = Sort012(head);
    print(head);
}