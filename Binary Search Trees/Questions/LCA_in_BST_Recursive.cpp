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

Node* LCA(Node* root, int n1, int n2){
    // Base Case
    if(root == NULL) return NULL;

// If root is larger than n1 and n2 then search in left Subtree
    if(root->data > n1 && root->data > n2){
        return LCA(root->left,n1,n2);
    }
    // If root is smaller than n1 and n2 then search in right Subtree
    if(root->data < n1 && root->data < n2){
        return LCA(root->right,n1,n2);
    }
    // If root is greater than a and smaller than b or greater than ba nd smaller than a then root is the LCA
    else{
        return root;
    }
}

int main(){
    Node* root = NULL;

    // 20 8 22 4 12 10 14 -1
    cout<<"Enter Data to Create BST: ";
    takeInput(root);

    levelOrderTraversal(root);

    int n1,n2;
    cout<<"Enter n1, n2: ";
    cin>>n1>>n2;

    root = LCA(root,n1,n2);

    cout<<"The lca of n1 and n2 is: "<<root->data<<endl;
}   