#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(vector<vector<int>> &people, int a, int b){
    if(people[a][b] == 1){
        return true;
    }
    
    return false;
}

int celebrity(vector<vector<int>> &people, int n){
    stack<int> st;
    // Step 1:- Push all people into the stack
    for(int i=0;i<n;i++){
        st.push(i);
    }

    // Step 2:-   Get 2 Elements and Discard them
    while(st.size() > 1){   // Jabtak size is greater then equal to one tabtak pop() 2 elements
        int a = st.top();    // 'a' banao joh top ki value store karega aur 
        st.pop();   // Uske baad pop kar dega

        int b = st.top();  // 'b' banao joh ki 2nd top ki value store karega aur 
        st.pop();   // Uske baad pop kardega

        if(knows(people,a,b)){   // Check karko ki, kya 'a' 'b' ko jaanta hai 
            st.push(b);     // Agar janta hai toh 'b' mein stored value ko phirse stack mein ush kardo he can be a possible celebrity
        }
        else{      // Agar 'a' 'b' ko nahi janta hai then
            st.push(a);    // push 'a' into the stack he can be a possible celebrity 
        }
    }

    int candidate = st.top();   // Joh bhi top par hoga wo ek potential celebrity ho sakta hai toh ab hame verify karna hai
    // Step 3:- Single Element in the Stack is Potential Celebrity
    // So veruify it

    bool rowCheck = false;   // Ham rows check karenge top wale element ka, if he is a celebrity then uske rows mein all zero's honge means he doen't know anyone
    int zeroCount = 0;   // zeroCount banao joh zero ka count rakhega

    for(int i=0;i<n;i++){    // Loop until size (size is the number of people at the party)
        if(i != candidate && people[candidate][i] == 0){   // If elements in the row is 0 and skip diagonal
            zeroCount++;   // Increase zeroCount
        }
    }

    // All Zeros
    if(zeroCount == n-1){    // Agar zeroCount == size matlab all elements in row is 0
        rowCheck = true;   // So rowCheck mein woh pass ho gaya so mark true
    }

    // Column Check 
    bool colCheck = false;   // Ab Column check karo, if he is a celebrity then all elements in his columns sould be 1 means everyone knows him
    int oneCount = 0;     //  oneCount banao joh count rakhega ki kitne 1 hai
    for(int i=0;i<n;i++){    
        if(i != candidate && people[i][candidate] == 1){    // If the elements in the column is 1 and skip diagonal
            oneCount++;   // increase oneCount
        }
    }

    if(oneCount == n-1){   // Check oneCount if it is equal to size-1 then 
        colCheck = true;   // Toh woh colCheck mein pass ho gaya
    }

    if(rowCheck == true && colCheck == true){    // Ab ham check karenge ki agar woh dono mein paas ho gaya 
        return candidate;   // then he is a celebrity return celebrity
    }
    else{
        return -1;    // If he fails in even one test then check for another if noone setifies both conditions then return -1
    }
}

int main(){
    int n;
    cout<<"Enter Number of people at the Party: ";
    cin>>n;

    if(n == 0){
        cout<<"Invalid number of People!";
        return 0;
    }

    vector<vector<int>> people(n, vector<int> (n));
    cout<<"Enter Number in Binary: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>people[i][j];
        }
    }

    cout<<"Array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<people[i][j]<<" ";
        }
        cout<<endl;
    }

    int celeb = celebrity(people,n);

    if(celeb == -1){
        cout<<"There is no Celebrity at the Party"<<endl;
    }
    else{
        cout<<"Celebrity is Person: "<<celeb<<endl;
    }
}