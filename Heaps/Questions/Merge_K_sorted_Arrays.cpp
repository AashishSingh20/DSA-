#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Method 1
// Using pair and minheap
// vector<int> mergeKSorted(vector<vector<int>> &mat, int k){

//     vector<pair<int,pair<int,int>>> temp;
//     for(int i=0;i<k;i++){
//         temp.push_back({mat[i][0],{i,0}});
//     }
    
//     // data,row,col
//     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq(temp.begin(),temp.end());

//     vector<int> ans;  // Vector which will store sorted Data

//     pair<int,pair<int,int>> element;
//     int i,j;  // Here i represents row and j represents column  

//     while(!pq.empty()){
//         element = pq.top();
//         pq.pop();
//         ans.push_back(element.first);
//         i = element.second.first;
//         j = element.second.second;

//         if(j+1 <= k){
//             pq.push({mat[i][j+1],{i,j+1}});
//         }
//     }
//     return ans;
// }

// Method 2
// Without using pair
// using Minheap
class Node{
    public:
        int data;
        int row;
        int column;
    
    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->column = col;
    }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

vector<int> mergeKSorted(vector<vector<int>> &mat, int k){
    priority_queue<Node*,vector<Node*>,compare> minheap;

    // Step 1:- Saare Arrays ke 1st Element ko minheap mein daldo
    for(int i=0;i<k;i++){
        Node* temp = new Node(mat[i][0],i,0);
        minheap.push(temp);
    }

    // Stores Final Values
    vector<int> ans;

    // Step 2:- top element ko ans mein store kardo
    // And uske row ke next element ko heap mein daldo
    while(minheap.size() > 0){
        Node* temp = minheap.top();
        ans.push_back(temp->data);
        minheap.pop();

        // Tells us from which row did temp belong to
        int i = temp->row;
        int j = temp->column;

        // Step 3:- If next elements exists in temp's row and it is less then row size
        // Create next pointer and insert next element from temp's row into the heap
        if(j+1 < mat[i].size()){
            Node* next = new Node(mat[i][j+1],i,j+1);
            minheap.push(next);
        }
    }

    return ans;
}

// Method 3 using divide and conquer

int main(){
    int m;
    cout<<"Enter Row Size: ";
    cin>>m;

    int n;
    cout<<"Enter Column Size: ";
    cin>>n;

    vector<vector<int>> mat;
    cout<<"Enter Matrix Elements: ";
    // 1 3 5 7 2 4 6 8 0 9 10 11
    for(int i=0;i<m;i++){
        vector<int> col;
        for(int j=0;j<n;j++){
            int data;
            cin>>data;
            col.push_back(data);
        }
        mat.push_back(col);
    }

    int k = m;   // Number of Rows = number of arrays

    vector<int> ans = mergeKSorted(mat,k);
    cout<<"Sorted Array after Merging: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}