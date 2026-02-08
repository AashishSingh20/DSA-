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

void levelOrderTraversal(Node* &root){
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

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
    // Base Case
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){   // Agar curr len and max len same hai then 
            maxSum = max(maxSum,sum);  // maxsum mein jis len ka sum max hoga woh daldena
        }
        return;
    }

    // Calculate sum ( sum == curr root data + previous value in sum)
    sum = sum + root->data;

    // Search left and right subtree
    solve(root->left,sum,maxSum,len+1,maxLen);
    solve(root->right,sum,maxSum,len+1,maxLen);
}

int sumOfLongRootToLeafPath(Node* root){
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root,sum,maxSum,len,maxLen);
    return maxSum;
}   

int main(){
    Node* root = NULL;

    // 4 2 5 7 1 2 3 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 
    levelOrderTraversal(root);

    int sum = sumOfLongRootToLeafPath(root);
    cout<<"Sum of Longest Subtree from root is: "<<sum<<endl;
}   