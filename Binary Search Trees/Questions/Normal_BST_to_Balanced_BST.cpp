#include<iostream>
#include<queue>
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

void inorder(Node* root, vector<int> &arr){
    if(root == NULL) return;

    // This stores the inorder of Tree in a vector
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

Node* inorderToBST(int start, int end, vector<int> &arr){
    if(start > end) return NULL;

    // Calculate mid
    int mid = start+(end-start)/2;
    // Mid wale element ko root banado and usmein mid wale ka data put kardo
    Node* root = new Node(arr[mid]);
    
    //Ab yeh sare operations phirse root ke left and right mein bhi karo
    root->left = inorderToBST(start,mid-1,arr);
    root->right = inorderToBST(mid+1,end,arr);
    
    // return root;
    return root;
}

Node* balancingBST(Node* root){

    vector<int> arr;
    // This Creates a vector of data in BST
    inorder(root,arr);

    int n = arr.size();
    root = inorderToBST(0,n-1,arr);

    return root;
}

int main(){

    Node* root = new Node(50);
    Node* b = new Node(30);
    Node* c = new Node(60);
    Node* d = new Node(20);
    Node* e = new Node(40);
    Node* f = new Node(70);
    Node* g = new Node(80);

    root->left = b;
    root->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    f->right = g;

    cout<<"Tree Before Balancing: "<<endl;
    levelOrderTraversal(root);

    root = balancingBST(root);

    cout<<"Tree After Balancing: "<<endl;
    levelOrderTraversal(root);
}   