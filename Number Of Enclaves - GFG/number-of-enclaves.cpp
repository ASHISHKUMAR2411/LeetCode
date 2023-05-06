//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        // find the number of boundary lands and make it visited and the answer will those which we are not visited and counted them usig bfs
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < m; i++){
            if(grid[0][i] == 1){
                q.push(make_pair(0,i));
                grid[0][i] = 2;
            }
            if(grid[n-1][i] == 1){
                q.push(make_pair(n-1,i));
                grid[n-1][i] = 2;
            }
        }
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1){
                q.push(make_pair(i, 0));
                grid[i][0] = 2;
            }
            if(grid[i][m-1] == 1){
                q.push(make_pair(i, m-1));
                grid[i][m-1] = 2;
            }
        }
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if(x_ < 0 or y_ < 0 or x_ >= n or y_ >= m or grid[x_][y_] != 1) continue;
                grid[x_][y_] = 2;
                q.push(make_pair(x_,y_));
            }
        }
        int count = 0; 
        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
                if(grid[i][j] == 2){
                    grid[i][j] = 1;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends