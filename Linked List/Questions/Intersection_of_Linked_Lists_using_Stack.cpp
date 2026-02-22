#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node* interSectPoint(Node* &firstHead, Node* &secondHead){
    stack<Node*> st1;
    stack<Node*> st2;

    Node* p = firstHead;
    while(p != NULL){
        st1.push(p);
        p = p->next;
    }

    p = secondHead;
    while(p != NULL){
        st2.push(p);
        p = p->next;
    }

    Node* intersection = NULL;

    while(!st1.empty() && !st2.empty()){
        if(st1.top() == st2.top()){
            intersection = st1.top();
            st1.pop();
            st2.pop();
        }
        else{
            break;
        }
    }

    return intersection;
}

int main(){

    // Common part
    Node* common1 = new Node(8);
    Node* common2 = new Node(10);
    Node* common3 = new Node(12);

    common1->next = common2;
    common2->next = common3;

    // First List: 3 -> 6 -> 9 -> 8 -> 10 -> 12
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = common1;

    // Second List: 4 -> 5 -> 8 -> 10 -> 12
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common1;

    Node* intersection = interSectPoint(head1, head2);

    if(intersection){
        cout << "Intersection at node with data: ";
        cout << intersection->data << endl;
    } else {
        cout << "No intersection found" << endl;
    }

    return 0;
}