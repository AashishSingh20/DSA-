#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Node{
    public:
        int data;
        int row;
        int col;

    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

vector<int> findSmallestRange(vector<vector<int>> &mat,int k){
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<Node*,vector<Node*>,compare> minheap;
    
    // Create a min heap for 1st elements of all lists
    // Along with pushing row also track it's row and col
    // Calculate mini and maxi for the first k elements
    for(int i=0;i<k;i++){
        int element = mat[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        minheap.push(new Node(element,i,0));
    }

    int start = mini;
    int end = maxi;
    while(!minheap.empty()){
        Node* top = minheap.top();
        minheap.pop();
        mini = top->data;

        // If new difference between new range is less than difference between old range then
        // Update start and end(Update range)
        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        // Kya top mein joh element tha uska next element exist karta hai(Matlab next column exist karta hai) then
        // next int banao aur uskmein top ke row ka next element put kardo,check maxi and push in minheap
        if(top->col+1 < mat[top->row].size()){
            int next = mat[top->row][top->col+1];
            maxi = max(maxi,next);
            minheap.push(new Node(next,top->row,top->col+1));
        }
        else{
            // next element does not exist
            break;
        }
    }

    return {start,end};
}

int main(){
    int m,n;
    cout<<"Enter number of Rows and columns: ";
    cin>>m>>n;

    vector<vector<int>> mat;
    // 3 5
    // 4 7 9 12 15 0 8 10 14 20 6 12 16 30 50
    cout<<"Enter Lists in the matrix: ";
    for(int i=0;i<m;i++){
        vector<int> col;
        for(int j=0;j<n;j++){
            int data;
            cin>>data;
            col.push_back(data);
        }
        mat.push_back(col);
    }

    vector<int> ans = findSmallestRange(mat,m);
    cout<<"The Smallest Range in K Lists is: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

