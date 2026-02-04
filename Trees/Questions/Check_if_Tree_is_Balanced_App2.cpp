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

void buildFromLevelOrder(Node* &root){
    int data;
    cout<<"Enter data for root: ";
    cin>>data;
    root = new Node(data);
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftdata;
        cout<<"Enter Left Node for: "<<temp->data<<endl;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout<<"Enter Right Node for: "<<temp->data<<endl;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }     
    
    }
}

int heightOfBt(Node* root){

    // Base Case
    if(root == NULL){
        return 0;
    }

    int leftHeight = heightOfBt(root->left);
    int rightHeight = heightOfBt(root->right);

    int ans = max(leftHeight,rightHeight) + 1;  // Calculates the max height from left and right subtree and adds 1 which is the root node
    return ans;
}

pair<bool,int> isBalancedFast(Node* root){
    // Base Case
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);  // pair ke bool mein initially true hakha hai humne and pair ke int mein initially 0 hai
        return p;   // Agar Root NUll hua toh true return ho jayega
    }

    pair<bool,int> left = isBalancedFast(root->left);  // calculates height of left subtree and gives true or false
    pair<bool,int> right = isBalancedFast(root->right);  // calculates height of right subtree and gives true or false

    bool leftAns = left.first;    // stores bool we have got from left in leftAns
    bool rightAns = right.first;  // stores bool we have got from right in rightAns
    bool diff = abs(left.second - right.second) <= 1;   // Checks whether height of left - height of right is <= 1

    pair<bool,int> ans;  
    ans.second = max(left.second,right.second) + 1;  // This stores max height in second block of ans

    if(leftAns && rightAns && diff == true){   // If all leftAns, rightAns and diff are true then 
        ans.first = true;   // Put true in the frst block of ans
    }
    else{
        ans.first = false;  // Else put false
    }

    return ans;   // Return ans;
}

bool isBalanced(Node* root){
    return isBalancedFast(root).first;   // hame return bool mein chahiye aur bool pair ek 1st block mein hai so we call with .first
}

int main(){
    Node* root = NULL;

    // 5 8 6 3 7 9 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);

    if(isBalanced(root)){
        cout<<"Tree is Balanced!";
    }
    else{
        cout<<"Tree is not Balanced!";
    }
}