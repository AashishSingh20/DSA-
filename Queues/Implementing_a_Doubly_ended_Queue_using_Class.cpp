#include<iostream>
using namespace std;

class Deque{
    public:
        int *arr;
        int front;
        int rear;
        int size;

    public:
        Deque(int n){
            size = n;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        bool pushFront(int x){
            // Check if Queue is Full
            if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
                cout<<"Queue is Full!";
                return false;
            }
            // If First Element
            else if(front == -1 && rear != size-1){
                front = rear = 0;
            }
            // To maintain Cyclic Nature
            else if(front == 0){
                front = size-1; 
            }
            // Normal Flow
            else{
                front--;
            }
            arr[front] = x;
            return true;
        }

        bool pushRear(int x){
            // If Queue is Full
            if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
                cout<<"Queue is Full!";
                return false;
            }
            // If we have to insert 1st element
            else if(front == -1){
                front = rear = 0;
                arr[rear] = x;
            }
            // If front is somewhere in the middle and rear has reached the end and to maintain cyclic flow
            else if(rear == size-1 && front != 0){
                rear = 0;
                arr[rear] = x; 
            }
            // Normal Flow
            else{
                rear++;
            }
            // After Checking Conditions push into the rear of the queue
            arr[rear] = x;
            return true;
        }

        bool popFront(){
            // If Queue is Empty
            if(front == -1){
                cout<<"Queue is Empty!";
                return -1;
            }
            int ans = arr[front];
            // If Single Element in the Queue
            if(front == rear){
                front = rear = -1;
            }
            // If front has reached end and to maintain cyclic flow
            else if(front == size-1){
                front = 0;   // This is used to maintain cyclic nature
            }
            // Normal Flow
            else{
                front++;
            }
            return ans;
        }

        bool popRear(){
            // If Queue is Empty
            if(front == -1){
                cout<<"Queue is Empty!";
                return -1;
            }
            int ans = arr[rear];
            // If Single Element in the Queue
            if(front == rear){
                front = rear = -1;
            }
            // If rear has reached end and to maintain cyclic flow
            else if(rear == 0){
                rear = size-1;   // This is used to maintain cyclic nature
            }
            // Normal Flow
            else{
                rear--;
            }
            return ans;
        }

        int getFront(){
            if(isEmpty()){
                return -1;
            }
            return arr[front];
        }

        int getRear(){
            if(isEmpty()){
                return -1;
            }
            return arr[rear];
        }

        bool isEmpty(){
            if(front == -1){
                return true;
            }
            return false;
        }

        bool isFull(){
            if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))){
                return true;
            }
            else{
                return false;
            }
        }
};