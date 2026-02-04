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


bool isIdentical(Node* r1, Node* r2){
    // Base Case
    if(r1 == NULL && r2 == NULL){  // Agar dono NULL hua toh True return Kardo
        return true;
    }

    if(r1 == NULL || r2 == NULL){   // Agar dono mein se koi ek bhi NULL hua toh False return kardo
        return false;
    }

    bool left = isIdentical(r1->left,r2->left);  // Check left of both r1 and r2
    bool right = isIdentical(r1->right,r2->right);  // Check right of both r1 and r2

    bool value = r1->data == r2->data;  // value true ho jayegi agar r1 ka curr data r2 ke curr data se same hai toh
   
    if(left && right && value){   // Agar left, right and value sab treu aagaye toh return true
        return true;
    }
    else{    // else return false
        return false;
    }
}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;

    // 5 8 6 3 7 9 -1 -1 -1 -1 -1 -1 -1
    cout<<"Enter values for Tree 1: ";
    buildFromLevelOrder(root1);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    cout<<"Enter values for Tree 2: ";
    buildFromLevelOrder(root2);

    if(isIdentical(root1,root2)){
        cout<<"Yes, both Trees are identical";
    }
    else{
        cout<<"No, both trees are not identical";
    }
}   