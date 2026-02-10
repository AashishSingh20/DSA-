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

void solve(Node* root, vector<int> &arr){
    // Base Case
    if(root == NULL) return;

    solve(root->left,arr);
    arr.push_back(root->data);
    solve(root->right,arr);
}

int KthLargest(Node* root,int k){
    vector<int> arr;

    int largest = 0;
    solve(root,arr);
    int n = arr.size()-k+1;
    for(int i=0;i<n;i++){
        largest = arr[i];
    }
    return largest;
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

    int largest = KthLargest(root,k);

    cout<<"Kth Largest Element in BST is: "<<largest<<endl;
    levelOrderTraversal(root);
}