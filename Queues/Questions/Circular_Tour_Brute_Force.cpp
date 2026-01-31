#include<iostream>
#include<vector>
using namespace std;

int startStation(const vector<int> gas, const vector<int> cost){
    int n = gas.size();
    int startIndex = -1;   // Tells from which index to start
    
    for(int i=0;i<n;i++){
        // Initially gas is 0 in the truck
        int currGas = 0;
        bool flag = true;

        for(int j=0;j<n;j++){
            // Circular Index
            int idx = (i+j)%n;   // Gives us the circular index, index depends on the number of stations
            currGas = currGas + gas[idx] - cost[idx];

            // If currGas is less than 0, then it is not the correct start index
            if(currGas < 0){
                flag = false;
                break;
            }
        }

        // If flag is found true then that index is the correct starting index
        if(flag){
            startIndex = i;
            break;
        }
    }
    return startIndex;
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