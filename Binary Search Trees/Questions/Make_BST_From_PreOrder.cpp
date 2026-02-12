#include<iostream>
#include<queue>
#include<climits>
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

Node* solve(vector<int> &preorder, int mini, int maxi, int &index){
    // Base Case  
    // Agar ham Array se bahar chal gaye hai then return
    if(index >= preorder.size()) return NULL;

    // If element is smaller than mini and greater than maxi then return NULL 
    if(preorder[index] < mini || preorder[index] > maxi){
        return NULL;
    }

    // If we it lies between mini and maxi then
    // Create a root node and put value at the current index in root then
    // Increment index 
    Node* root = new Node(preorder[index++]);

    // Ab root ke left and right ke liye call through recursion
    // for left in maxi value of current root data will be copied
    root->left = solve(preorder,mini,root->data,index);
    
    // Similarly for right in mini the current root data will be copied
    root->right = solve(preorder,root->data,maxi,index);

    // Return root
    return root;
}

Node* bstFromPreorder(vector<int> &preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;

    int index = 0;
    Node* root = solve(preorder,mini,maxi,index);

    return root;
}

int main(){

    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;

    vector<int> preorder;
    cout<<"Enter Preorder Elements: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        preorder.push_back(data);
    }

    Node* root = bstFromPreorder(preorder);

    cout<<"Tree: "<<endl;
    levelOrderTraversal(root);
}