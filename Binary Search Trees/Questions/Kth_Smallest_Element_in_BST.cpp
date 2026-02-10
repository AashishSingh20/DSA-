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

Node* insertIntoBST(Node* &root, int data){
    // Base Case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    // If curr data is greater than root data insert in it's right
    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    // If curr data is smaller than root data insert in it's left
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

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

int solve(Node* root, int k, int &count){
    if(root == NULL) return -1;

    // L
    // Left mein jaate jao until last node or smallest node
    int left = solve(root->left,k,count);

    // If kth Smallest is found in left subtree, then return it 
    if(left != -1) return left;

    // N
    count++;
    // If current Node is kth smallest, return it
    if(count == k){
        return root->data;
    }

    // R
    // Else Process the right Subtree, and return it's value
    int right = solve(root->right,k,count);
    return right;
}

int KthSmallest(Node* root,int k){
    int count = 0;
    int small = solve(root,k,count);
    return small;
}

int main(){
    Node* root = NULL;

    // 100 50 110 25 70 120 60 115 -1
    cout<<"Enter Data to Create BST: ";
    takeInput(root);
    
    cout<<"BST: "<<endl;
    levelOrderTraversal(root);

    int k;
    cout<<"Enter value of k: ";
    cin>>k;

    int smallest = KthSmallest(root,k);

    cout<<k<<"th Smallest Element in BST is: "<<smallest<<endl;
    levelOrderTraversal(root);
}