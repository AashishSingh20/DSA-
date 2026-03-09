vector<int> mergeKSorted(vector<vector<int>> &mat, int k){

//     vector<pair<int,pair<int,int>>> temp;
//     for(int i=0;i<k;i++){
//         temp.push_back({mat[i][0],{i,0}});
//     }
    
//     // data,row,col
//     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq(temp.begin(),temp.end());

//     vector<int> ans;  // Vector which will store sorted Data

//     pair<int,pair<int,int>> element;
//     int i,j;  // Here i represents row and j represents column  

//     while(!pq.empty()){
//         element = pq.top();
//         pq.pop();
//         ans.push_back(element.first);
//         i = element.second.first;
//         j = element.second.second;

//         if(j+1 <= k){
//             pq.push({mat[i][j+1],{i,j+1}});
//         }
//     }
//     return ans;
// }
