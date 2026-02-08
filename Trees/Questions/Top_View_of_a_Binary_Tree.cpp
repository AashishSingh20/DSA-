#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

vector<int> topView(Node* &root){
    vector<int> ans;
    // Base Case
    if(root == NULL){
        return ans;
    }

    map<int,int> topNode;  // Here 1st int is the horizontal Distance and 2nd int is for data
    queue<pair<Node*,int>> q;
    
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // Maintain 1 to 1 mapping in map(If one value is present at the given HD then ignore the rest that come at the same HD)
        if(topNode.find(hd) == topNode.end()){   // Agar element is not found at the hd then return .end(Means not found) 
            topNode[hd] = frontNode->data;     // Agar not found hai toh hd ki position par frontNode ka data daldo 
        }

        // Check LeftNode and push in queue
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }

        // heck rightNode and push in queue
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    for(auto i : topNode){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    Node* root = NULL;

    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 
    levelOrderTraversal(root);

    vector<int> top_view = topView(root);
    cout<<"The vertical Order traversal of the tree is: ";
    for(int i=0;i<top_view.size();i++){
        cout<<top_view[i]<<" ";
    }
    cout<<endl;
}   