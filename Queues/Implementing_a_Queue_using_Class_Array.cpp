#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int size;
    int front;
    int rear;

    Queue(){
        size = 1000;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data){
        if(rear == size){
            cout<<"Queue is Full!";
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if(front == rear){
            cout<<"Queue is Empty!";
        }
        else{
            int ans = arr[front];   // Pop front se hota hai isliye aage wale element par ans ko set kardia
            arr[front] = -1;  // Agar front rear ke barabar nahi hai then front mein -1 daldo aur
            front++;   // front ko aage badhado
            if(front == rear){  // Agar aage bdhane ke baad front and rear phir equal hogaye then
                front = 0;   // Front ko bhi start mein daldo 
                rear = 0;   // and rear ko bhi start mein daldo
            }
            return ans;
        }
    }

    int front(){
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }
};