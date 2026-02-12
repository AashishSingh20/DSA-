#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    public:
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void levelOrderTraversal(Node* root){   // Also known as BFS
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);   // Acts as a separater (Tells us when that specific level has been completed)

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){   // Purana Level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){   // If queue has some child nodes 
                q.push(NULL);  // Yeh ek aur separater hai joh queue ke last mein rahega mein ham push kardenga
            }
        }
        else{
            cout<<temp->data<<" ";   // Print data when temp is not NULL    
            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){    
                q.push(temp->right);
            }
        }
    }
    cout<<endl;
}

// Function To Convert a Tree into a Sorted DLL
void convertIntoSortedDLL(Node* root, Node* &head){
    // Base Case
    if(root == NULL) return;

    // Right Part of the Tree ko DLL mein convert kardo
    convertIntoSortedDLL(root->right,head);

    // Root ke right ko head par point karwado
    root->right = head;

    // Agar head NULL nahi hai toh head ke left ko root par point karwado
    if(head != NULL){
        head->left = root;
    }

    // Ab head ko root par point karwado
    head = root;

    // Ab Left Part of the Tree ko DLL mein convert kardo
    convertIntoSortedDLL(root->left,head);

}

// Function to Merge LL
Node* mergeLL(Node* head1, Node* head2){
    // Ek head pointer banaya woh final merged LL ke head par point karega
    Node* head = NULL;

    // Ek tail banaya woh final merged LL ke tail par rpoint karega
    Node* tail = NULL;

    // Jabtak head1 NULL nahi hota and head2 NULL nahi hoata tabtak continue the loop
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                // head mein head1 ko daldo
                // tail ko bhi head1 par daldo since abhi 1st element hai
                // head1 ko aage badhado
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                // If head != NULL matlab LL has some elements
                // Tail ke right mein head1 ko daldo
                // head1 ke left ko tail par point karwado
                // tail ko head1 par daldo
                // head1 ko head1 ke right mein leke aajao joh tail hai ab
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                // head mein head1 ko daldo
                // tail ko bhi head1 par daldo since abhi 1st element hai
                // head2 ko aage badhado
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    // If head1 is not NULL but head2 becomes NULL
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    // If head1 NULL but head2 is not NULL
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

// Counts the Number of Nodes in the DLL
int countNodes(Node* head){
    int cnt = 0;

    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

Node* SortedLLToBST(Node* &head, int n){
    // Base Case
    if(n <= 0 || head == NULL) return NULL;

    // left Subtree mein operation perform karega
    Node* left = SortedLLToBST(head,n/2);

    // root ko head par rakhdenge
    Node* root = head;
    // Ab left Subtree banayenge
    root->left = left;

    // head ko aage badhado
    head = head->right;

    // Ab right Subtree banayenge
    root->right = SortedLLToBST(head,n-n/2-1);
    return root;
}

Node* mergeBST(Node* root1, Node* root2){

    // Step 1:- Convert BST into Sorted DLL in-place
    // head1 banao oh NULL par point kar rahi hai
    Node* head1 = NULL;
    // Ab us Tree ko 
    convertIntoSortedDLL(root1,head1);
    // If head1 exists then uske left ko NULL banado
    if(head1) head1->left = NULL;

    // head2 banao oh NULL par point kar rahi hai
    Node* head2 = NULL;
    // Ab us Tree ko 
    convertIntoSortedDLL(root2,head2);
    // If head2 exists then uske left ko NULL banado
    if(head2) head2->left = NULL;

    // Step 2:- Merge Sorted DLL
    // and assign head to the starting node of the merged LL
    Node* head = mergeLL(head1,head2);

    // Step 3:- Convert Sorted LL into BST
    // returns BST after converting it from LL
    // coutNodes counts the length of LL
    int n = countNodes(head);
    return SortedLLToBST(head,n);
}

int main(){
    // Creating BST 1  
    Node* root1 = new Node(3);
    Node* b = new Node(1);
    Node* c = new Node(5);

    root1->left = b;
    root1->right = c;

    // Creating BST 2
    Node* root2 = new Node(4);
    Node* d = new Node(2);
    Node* e = new Node(6);

    root2->left = d;
    root2->right = e;

    // Tree 1
    levelOrderTraversal(root1);
    // Tree 2
    levelOrderTraversal(root2);

    // Merged Tree
    Node* root = mergeBST(root1,root2);
    levelOrderTraversal(root);
}