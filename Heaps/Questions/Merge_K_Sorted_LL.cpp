#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

Node* createLL(vector<int> &arr){
    if(arr.empty()) return NULL;
    
    Node* head = new Node(arr[0]);
    Node* temp = head;
    
    for(int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    
    return head;
}

void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* mergeKLL(vector<Node*> &arr){
    priority_queue<Node*,vector<Node*>,Compare> minheap;

    int k = arr.size();
    if(k == 0) return NULL;
    // Step 1:- 
    for(int i=0;i<k;i++){
        if(arr[i] != NULL){
            minheap.push(arr[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;
    while(minheap.size() > 0){
        Node* top = minheap.top();
        minheap.pop();

        if(top->next != NULL){
            minheap.push(top->next);
        }

        if(head == NULL){
            // If LL is empty point head and tail to top
            head = tail = top; 
        }
        else{
            // Insert at End   
            tail->next = top;
            tail = top;
        }
    }

    return head;    
}

int main(){

    vector<int> arr1 = {4,7,11};
    vector<int> arr2 = {3,10};
    vector<int> arr3 = {2,8,13};
    vector<int> arr4 = {5,9};
    vector<int> arr5 = {1};
    vector<int> arr6 = {6,12};

    Node* l1 = createLL(arr1);
    Node* l2 = createLL(arr2);
    Node* l3 = createLL(arr3);
    Node* l4 = createLL(arr4);
    Node* l5 = createLL(arr5);
    Node* l6 = createLL(arr6);

    vector<Node*> lists = {l1,l2,l3,l4,l5,l6};

    Node* result = mergeKLL(lists);

    cout<<"Merged Linked List: ";
    printList(result);
}