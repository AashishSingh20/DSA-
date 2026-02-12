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

void solve(Node* root, vector<int> &inorder){
    if(root == NULL) return;
    
    // This will give sorted data in the vector
    // Left Mein jao 
    solve(root->left,inorder);
    // Leftmost element ko daldo and aage badhjao
    inorder.push_back(root->data);
    // Ab right elements ko daldo
    solve(root->right,inorder);
}

bool findTarget(Node *root, int target) {
    vector<int> inorder;
    solve(root,inorder);
    
    // Use 2 pointers to find the if there exists numbers in array whose sum is equal to target
    int n = inorder.size();
    int i = 0;
    int j = n-1;
    
    while(i<j){
        int sum = inorder[i] + inorder[j];
        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else if(sum < target){
            i++;
        }
    }
    return false;
}

int main(){
    Node* root = NULL;

    // 20 8 22 4 12 10 14 -1
    cout<<"Enter Data to Create BST: ";
    takeInput(root);

    levelOrderTraversal(root);

    int target;
    cout<<"Enter Target"<<endl;
    cin>>target;

    if(findTarget(root,target)){
        cout<<"There are nodes in the BST whose pair sum is equal to target.";
    }
    else{
        cout<<"There are no nodes in the BST whose pair sum is equal to target.";
    }
}   