#include<iostream>
using namespace std;

class kQueues{
    public:
        int n;   // n is the size of array
        int k;  // k is the number of queues
        int *arr;   // Signifies the main Array
        int *front;  // Points to the front of the queues
        int *rear;   // Points to the rear of the queues
        
        int *next;  // Maintains a different array which helps us keep record of next freespace or next element in the array
        int freespot;  // Tells us where is freespot in the array if it is -1 then array is full

    public:
        kQueues(int n, int k){
            this->n = n;
            this->k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0;i<k;i++){
                front[i] = -1;  // Initialize all data members of front and rear as -1 
                rear[i] = -1;
            }
            next = new int[n];
            for(int i=0;i<n;i++){  // Initialize all data members in next array with number from 1 to n-2
                next[i] = i+1;
            }
            next[n-1] = -1;   // in place of last data member in next put -1 which signifies there are no more freespaces

            arr = new int[n];
            freespot = 0;
        }

        // Here we are using qn-1 inside the functions as we are using 0 based indexing
        void enqueue(int data, int qn){   
            // Check for OverFlow
            if(freespot == -1){
                cout<<"OverFlow!"<<endl;
                return;
            }

            // Find index where insertion of new element will take place
            int index = freespot;

            // Update freespot
            freespot = next[index];

            // If the element to be inserted is the 1st element of that particular queue
            if(front[qn-1] == -1){   
                front[qn-1] = index;
            }
            // If the element to be inserted is not the 1st element of that particular queue(Link new element to the previous element)
            else{
                next[rear[qn-1]] = index;
            }

            // Update next ka index
            next[index] = -1;

            // Update Rear
            rear[qn-1] = index;

            // Push Element
            arr[index] = data;
        }

        int dequeue(int qn){
            // Check for UnderFlow
            if(front[qn-1] == -1){ 
                cout<<"UnderFlow!"<<endl;
                return -1;
            }

            // Find index from the respective queue to pop
            int index = front[qn-1];

            // Update front(ab front apne next element par jayega)
            front[qn-1] = next[index];

            // Update next index which will tell us location of freespot 
            next[index] = freespot;

            // Update freespot
            freespot = index;

            // Print dequeued data 
            return arr[index];
        }
};

int main(){
    kQueues q(10,3);

    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
}