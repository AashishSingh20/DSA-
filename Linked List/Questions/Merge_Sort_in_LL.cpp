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
    Node* temp = head;
    if(temp == NULL){
        cout<<"List is Empty.";
        return;
    }
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* findMid(Node* head){
    if(head == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;  // Isko next se chau
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;  // Pointer temp is pointing towards the new Node ans

    // Merge 2 Sorted LL
    while(left != NULL && right != NULL){  // Loop until both left and right doesn't become NULL
        if(left->data < right->data){  //  If data in left is smaller then data in right then
            temp->next = left;  // temp ke next mein left ki value daldo
            temp = left;  // temp ko left ar le jao
            left = left->next;  // Aur left ko aage badhado
        }
        else{               // agar left ka data is greater than right ka data then
            temp->next = right;  // temp ke next mein right ko daldo
            temp = right;   // temp ko aage badhake right par le aao
            right = right->next;  // right k o aage badhado
        }
    }

    while(left != NULL){  // Agar right NULL ho gaya hai toh left ke data ko ans mein dalte jao
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL){  // Agar left NULL ho gaya hai tph right ke data ko ans mein dalte jao
        temp->next = right;
        temp = right;
        right = right->next; 
    }

    ans = ans->next;  // since ans mein -1 hai isliye ans ko update karke ans ke next par shift kardo
    return ans;   // return ans jismein sab sorted values hai
}

Node* mergeSortLL(Node* head){
    // Base Case
    if(head == NULL || head->next == NULL){  // Agar head NULL hai yaa head ka next nodes NULL hai toh return kardo head a single nodes is already sorted
        return head;
    }

    Node* mid = findMid(head);   // Is function se hame mid pata chal Jayega
    
    //Step 1:- Dividing the LL
    Node* left = head;  // ab Ham left pointer banayenge joh head ko point karega
    Node* right = mid->next;  // right pointer banayenge joh mid ke next node ko point karega
    mid->next = NULL;  // mid ke next ko ham NULL kardenge kyuki LL half karne ke baad first LL mein mid last hoga toh woh NULL ko hi toh point karega

    //Step 2:- Recursive Calls to sort both left LL and Right LL
    left = mergeSortLL(left);
    right = mergeSortLL(right);

    //Step 3:- Merge both LL
    Node* result = merge(left,right);  // Calls merge function ans stores the sorted Merged list in result
    return result;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    int n,ele;
    cout<<"Enter number of Nodes in LL: ";
    cin>>n;
    
    cout<<"Enter LL Elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        tailInsert(head,tail,ele);
    }

    head = mergeSortLL(head);
    cout<<"Sorted List: ";
    print(head);
}