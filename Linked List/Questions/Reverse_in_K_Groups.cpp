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

    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;  // Tail ka next node 'temp' ko banado
    tail = temp;  // tail ko update karke 'temp' ke paas dedo
}

Node* kreverseLL(Node* &head, int k){
    // Base Case
    if(head == NULL){
        return head;
    }

    // Step 1: Reverse First k nodes
    Node* prev = NULL; 
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    while(curr != NULL && count < k){  // Loop tabtak chalao jabtak 'curr' wala node NULL na ho jaye aur jabtak count k se kam hai
        next = curr->next;   // 'next' ko 'curr' ke next node jo hai woh set kardo 
        curr->next = prev;  // ab 'curr' ke next node ko prev node par point karwado
        prev = curr;  // 'prev' ko 'curr' par le aana(aage badhado prev ko)
        curr = next;  // ab 'curr' ko 'next' par le aana('curr' ko bhi aage badhado)
        count++;  // count badhte rahega jabtak woh k ke se chhota hai
    }

    // Step 2: Recursion deklega aage ka
    if(next != NULL){   // Agar next NULL nahi hua hai toh next k group par reversal lagao
        head->next = kreverseLL(next,k);  // 1st group ke reversal ke baad head hi lastmein ho jaega toh head->next matlab head ke baad dusre group ko jodh do
    }

    // Step 3: Return Head of previous List
    return prev;  // ab head update karke prev ko head dedo 
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int n,ele;
    cout<<"Enter number of nodes in LL: ";
    cin>>n;

    if(n==0){
        cout<<"Linked List is Empty";
        return 0;
    }

    if(n==1){
        cout<<"Reverse is Same as Original";
        return 0;
    }
    
    cout<<"Data members: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        tailInsert(head,tail,ele);
    }

    int k;
    cout<<"Enter by how many groups you want to reverse(k): ";
    cin>>k;
    head = kreverseLL(head,k);  // 'prev' joh return hua hai usko head mein dalke head ko update kardo
    cout<<"Reverse: ";
    print(head);
}