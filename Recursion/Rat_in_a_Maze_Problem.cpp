#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& m, int n, vector<vector<int>>& visited){
    if((x>=0 && x<n) && (y>=0 && y<=n-1) && m[x][y] == 1 && visited[x][y] == 0){
        return true;
    }
    return false;
}

void solve(vector<vector<int>>& m, int n,vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path){
    if(x == n-1 && y == n-1){   // Jab x and y coordinate last mein pohach jaye toh return kardo
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;   // First element at source is 1 so visited matrix mein bhi visited mark kardo

// Choices - D,L,R,U  -- Lexicographical order
    // Down
    int new_x = x+1;
    int new_y = y;
    if(isSafe(new_x, new_y, m, n, visited)){
        path.push_back('D');
        solve(m, n, ans, new_x, new_y, visited, path);
        path.pop_back();
    }
    
    // Left
    new_x = x;
    new_y = y-1;
    if(isSafe(new_x, new_y, m, n, visited)){
        path.push_back('L');
        solve(m, n, ans, new_x, new_y, visited, path);
        path.pop_back();
    }
    
    // Right
    new_x = x;
    new_y = y+1;
    if(isSafe(new_x, new_y, m, n, visited)){
        path.push_back('R');
        solve(m, n, ans, new_x, new_y, visited, path);
        path.pop_back();
    }
    
    // Up
    new_x = x-1;
    new_y = y;
    if(isSafe(new_x, new_y, m, n, visited)){
        path.push_back('U');
        solve(m, n, ans, new_x, new_y, visited, path);
        path.pop_back();
    }  

    visited[x][y] = 0;   // Ab visited Element ko firse 0 kardo durse possible raste ko dhundh paye isliye
}


int main(){
    int n;
    cout<<"Enter Matrix Size: ";
    cin>>n;

    vector<vector<int>> m(n,vector<int>(n));

    cout<<"Enter Matrix Elements: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }
    
    vector<string> ans;   // string of all possible solutions possible
    if(m[0][0] == 0){   // Agar Matrix ka pehla element is 0 hai toh aage jayega hi nahi so return empty ans string
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
    }
    
    cout<<"Matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    int src_x = 0;  // x co-ordinate of source
    int src_y = 0;  // y co-ordinate of source

    vector<vector<int>> visited(n,vector<int>(n,0));  // visited wala vector bana diya aur uske saare elements ko 0 se initialize kar diya

    string path = "";   // It is used to track the paths we take to reach from source to destination

    solve(m,n,ans,src_x,src_y,visited,path);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
}