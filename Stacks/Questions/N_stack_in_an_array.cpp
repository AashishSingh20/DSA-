#include<iostream>
using namespace std;

class NStack{
    public:
        int *arr;    //  Create a Main Array that stores all values of stacks
        int *top;   // Create top which tells us what is at the top of each stack 
        int *next;   //  This points to the next top element in the stack or it points to the next free space in the array

        int n,s;   // n is the number of stacks, s is the size of the main array
        int freespot;   // This variable helps us to find the next freespot to insert our element

    public:
        // Constructor
        NStack(int N, int S){
            n = N;    // n is the size of the array
            s = S;    // s is the number of stacks

            arr = new int[s];   // arr banao s size ka(yeh main array hai)
            top = new int[n];  // top naam ka bhi ek array banao s size ka yeh har stack ke top element ko store karega
            next = new int[s];  // next naam ka ek array banao joh d kaam karega(if next space is empty it will point to next free space or if next space is full then it will tell next element after stack top)

            // Initialize top
            for(int i=0;i<n;i++){   // Initially top mei sab -1 put kardo
                top[i] = -1;
            }

            // Initialize next
            for(int i=0;i<s;i++){  // next mein i+1 karke elements initialize karte jao
                next[i] = i+1;
            }

            // Update last index value to -1   // Last index of next will have -1 stored as there is no free space after it
            next[s-1] = -1;

            // Initialize freespot
            freespot = 0;    // Intitially value of freespot is 0
        }

        bool push(int x, int m){
            // check for overflow
            if(freespot == -1){   // If freespot is -1 matlab there is no free space(OverfLow) we are at the end of next
                return false;   // so return false
            }

            // Find Index
            int index = freespot;  // Agar freespot is not 1 then index mein freespot ki value put kardo

            // Update freespot
            freespot = next[index];    // Freespot mein next ka index daldo joh free hai

            // Insert element into the main Array
            arr[index] = x;     // arr mein new value ko push kardo at the free index

            // Update next
            next[index] = top[m-1];   // next ke free index mein top ke last ki value put kardo(Initially it is -1 so put next[index] = -1)

            // Update top
            top[m-1] = index;   // top mein index put kardo

            return true;    // Return true 
        }

        int pop(int m){
            // Check Underflow
            if(top[m-1] == -1){   // If top ke ke last mein -1 hai matlab stack is empty(UnderfLow)
                return -1;
            }

            // Set index
            int index = top[m-1];    // Index mein top ki value store kardo

            // Update top
            top[m-1] = next[index];   // Top mein next ke index ki value store kardo

            // Update next
            next[index] = freespot;   // next ke index mein freespot ki value put kardo matlab1 freespot hai been created

            // Update freespot
            freespot = index;   // freespot mein index dedo joh index khali hai
            
            // Return arr 
            return arr[index];   // return arr at the index
        }
};