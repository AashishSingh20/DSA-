#include<iostream>
#include<algorithm>
using namespace std;


class Node{
// Data members of class Node
    public:
        int data;
        Node* next;  

// Constructor
    public:
        Node(int data){
            this->data = data;
            this->next = NULL; 
        }
};

void tailInsert(Node* &head, Node* &tail, int data){  

Node* temp = new Node(data);

    if (head == NULL) { 
        head = temp;  
        tail = temp;  
        return;  
    }

    tail->next = temp; 
    tail = temp; 
}

void print(Node* &head){  // Same as as above for taking by reference
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* Sort012(Node* head){
    int zeroCount = 0;  // Keeps track of number of 0's in LL
    int oneCount = 0;   // Keeps track of number of 1's in LL
    int twocount = 0;   // Keeps track of number of 2's in LL
    Node* temp = head;   // initialize temp at head

    while(temp != NULL){     
        if(temp->data == 0){   // agar temp mein joh data hai woh 0 hai to zeroCount ko badhado
            zeroCount++;
        }
        else if(temp->data == 1){   // agar temp mein joh data hai woh 1 hai to oneCount ko badhado
            oneCount++;
        }
        else{            // agar temp mein joh data hai woh 2 hai to twoCount ko badhado
            twocount++;
        }
        temp = temp->next;   // temp ko aage badhate jao
    }

    temp = head;   // temp ko phirse head par rakhdo
    while(temp != NULL){   
        if(zeroCount != 0){   // agar zerocount 0 nahi hai toh temp ke data mein 0 daldo aur zeroCount ko kam karte jao 
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){  // Agar oneCount 0 nahi hai toh temp ke data mein 1 daldo aur oneCount ko kam karte jao(it will run when zeroCount is 0)
            temp->data = 1;
            oneCount--;
        }
        else{         // Agar twoCount 0 nahi hai toh temp ke data mein 2 daldo aur twoCount ko kam karte jao(it will run when zeroCount is 0 and oneCount is 0)
            temp->data = 2;
            twocount--;
        }
        temp = temp->next;  // temp ko aage badhate jao
    }
    return head;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int n,ele;
    cout<<"Enter How Many Elemets in the LL: ";
    cin>>n;

    cout<<"Enter LL Elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        tailInsert(head,tail,ele); // Inserts elements in the LL from Behind
    }
    
    head = Sort012(head);
    print(head);
}