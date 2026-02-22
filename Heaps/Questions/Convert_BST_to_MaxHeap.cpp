#include<iostream>
#include<vector>
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

void buildLevelOrder(Node* &root){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter Left Node for "<<temp->data<<endl;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter Right Node for "<<temp->data<<endl;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);            
        }
    }
}

void levelOrderPrint(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

void inorder(Node* root, vector<int> &arr){
    if(root == NULL) return;
    
    // Inorder traverse karke ek sorted Array banalo
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

void fillPostOrder(Node* root,vector<int> &arr, int &index){
        if(root == NULL) return;
        
        // Us inorder ko PostOrder ke hisab se phir tree mein insert kardo
        fillPostOrder(root->left,arr,index);
        fillPostOrder(root->right,arr,index);
        root->data = arr[index++];
}

int main(){
    Node* root = NULL;

    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 
    buildLevelOrder(root);

    vector<int> arr;
    cout<<"Inorder of Tree: "<<endl;
    inorder(root,arr);

    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int index = 0;
    fillPostOrder(root,arr,index);

    cout << "Level Order After Converting to Max Heap:" << endl;
    levelOrderPrint(root);
} 