#include<iostream>
#include<vector>
using namespace std;

int startStation(const vector<int> gas, const vector<int> cost){
    int n = gas.size();

    int deficit = 0;   // Initially petrol ki kami nahi hai
    int balance = 0;  // Initially balance bhi 0 hai
    int start = 0;  // Start bhi first index se hi hoga

    for(int i=0;i<n;i++){
        balance += gas[i] - cost[i];  
        
        if(balance < 0){
            deficit += balance;  // Agar balance negative ho gaya toh usse deficit mein store kardo 
            start = i+1;  // start ko current index se ek aage leke chale jao
            balance = 0;  // Since new jagah start ba gayitoh balance ki bhi 0 kardo
        }  
    }

    if(deficit +  balance >= 0){  // Agar difference between deficit and balance is greater than or equal to 0 then return start (tour is completed)
        return start;
    }
    else{
        return -1;   // Else return -1 (circular tour is not possible)
    }
}

int main(){
    int n;
    cout<<"Enter the number of Petrol Pumps: ";
    cin>>n;

    vector<int> gas;
    cout<<"Enter gas at each Stations: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        gas.push_back(data);
    }

    vector<int> cost;
    cout<<"Enter Cost at each gas Stations: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        cost.push_back(data);
    }

    int start = startStation(gas,cost);
    cout<<"The Truck should start from station "<<start<<" to complete one circular trip."<<endl;
}