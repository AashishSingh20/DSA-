#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &visited, vector<vector<int>> &maze, int n){
    // Condition
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && maze[newx][newy] == 1 && visited[newx][newy] == 0){
        return true;
    }
    else{
        return false;
    }
}


void solve(int x, int y,vector<vector<int>> &maze, int n, vector<string> &ans, vector<vector<bool>> &visited, string path){
    // Base Case
    // If destination is reached store ans in ans
    
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    
    // Instead of using visited we can just mark visited cells as 0 then restore it during backtracking
    // maze[x][y] = 0  after visiting the node
    // maze[x][y] = 1  when backtracking
    
    // Movements  D L R U
    // Based of DLRU (When down = x+1; left = x, right = x, up = x-1)
    // Same for y (Down = y, Left = y-1, Right = y+1, Up = y)
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,-1,1,0};
    char move[4] = {'D','L','R','U'};

    visited[x][y] = 1;  // Koi index par jaa chuke ho toh usse visited mark kardo

    for(int i=0;i<4;i++){
        int newx = x + dx[i];  // Gets new x coordinate
        int newy = y + dy[i];  // Gets new y coordinate

        if(isSafe(newx,newy,visited,maze,n)){
            solve(newx,newy,maze,n,ans,visited,path + move[i]);
        }
    }

    visited[x][y] = 0;  // Jab backtrack kar rahe ho toh visited ko 0 mark karte jao
}  

vector<string> ratInMaze(vector<vector<int>> &maze, int n){
    // Stores final answer
    vector<string> ans;
    
    // Base Case
    if(maze[0][0] == 0){
        cout<<"No route Possible!";
        return ans;
    }

    // Keeps Record of all visited spots
    vector<vector<bool>> visited(n,vector<bool>(n,0));

    string path = "";  // Stores path we have found

    solve(0,0,maze,n,ans,visited,path);
    return ans;
}

int main(){
    int n;
    cout<<"Enter Matrix Size: ";
    cin>>n;

    /*  1 0 0 0 
        1 1 0 0 
        1 1 0 0 
        0 1 1 1 */
    vector<vector<int>> maze;
    cout<<"Enter Values in maze in 0's and 1's: "<<endl;
    for(int i=0;i<n;i++){
        vector<int> col;
        for(int j=0;j<n;j++){
            int data;
            cin>>data;
            col.push_back(data);
        }
        maze.push_back(col);
    }

    vector<string> ans = ratInMaze(maze,n);
    cout<<"The Possible Paths: ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}