#include<iostream>
#include<queue>
#include<vector>
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

vector<int> zigZagTraversal(Node* root){
    vector<int> ans;
    
    if(root == NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;
    while(!q.empty()){   // Jabtak queue is not empty process every level
        int size = q.size();   // Size banao jismein q ka size hoga
        vector<int> arr(size);  // arr banao aur uska size fix kardo ( Har level mein arr ka size update hoga)

        // Process Level
        for(int i=0;i<size;i++){   // Loop until the sise of the queue
            Node* frontNode = q.front();   // frontNode mein queue ke front ka element daldo 
            q.pop();   // queue ko pop kardo

            // Normal Insert or reverse insert check hoga
            int index = leftToRight ? i : size - i - 1;    // Agar leftToRight true hai toh insert from left to right or insert from right to left
            arr[index] = frontNode->data;     // arr mein us index ka data daldo

            if(frontNode->left != NULL){    // if frontNode ka left is not NULL then push it in queue
                q.push(frontNode->left);
            }
            if(frontNode->right != NULL){   // if frontNode ka left is not NULL then push it in queue
                q.push(frontNode->right);
            }
        }
    
        // Direction change karni hai
        leftToRight = !leftToRight;    // Agar leftToRight true hai toh false ho jayega aur agar false hai toh true ho jayega

        for(auto i: arr){
            ans.push_back(i);    // push all values stored in ans 
        }
    }
    return ans;     // return ans
}

int main(){
    Node* root = NULL;

    // 5 8 6 3 7 9 -1 -1 -1 -1 -1 -1 -1
    levelOrderTraversal(root);

    vector<int> zigZag = zigZagTraversal(root);
    cout<<"The Zigzag traversal of the tree is: ";
    for(int i=0;i<zigZag.size();i++){
        cout<<zigZag[i]<<" ";
    }
    cout<<endl;
}   