#include<iostream>
using namespace std;

class circularQueue{
    public:
        int *arr;
        int size;
        int front;
        int rear;

    public:
        circularQueue(int n){
            size = n;
            arr = new int[size];
            front = rear = -1;
        }

        bool enqueue(int value){
            // If Queue is Full
            if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
                cout<<"Queue is Full!";
                return false;
            }
            // If we have to insert 1st element
            else if(front == -1){
                front = rear = 0;
                arr[rear] = value;
            }
            // If front is somewhere in the middle and rear has reached the end
            else if(rear == size-1 && front != 0){
                rear = 0;
                arr[rear] = value; 
            }
            // Normal Flow
            else{
                rear++;
            }
            // After Checking Conditions push into the rear of the queue
            arr[rear] = value;
            return true;
        }

        int dequeue(int value){
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
            // If front has reached end 
            else if(front == size-1){
                front = 0;   // This is used to maintain cyclic nature
            }
            // Normal Flow
            else{
                front++;
            }
            return ans;
        }
};