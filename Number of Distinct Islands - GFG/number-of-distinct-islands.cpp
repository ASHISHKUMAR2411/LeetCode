//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // void dfs(int i, int j, int n, int m, vector<vector<int>> &grid){
    //     if(i < 0 or j < 0 or i >= n or i >= m or grid[i][j] == 0) return;
    //     grid[i][j] = 0;
    //     int dx[] = {0,0,-1,1};
    //     int dy[] = {-1,1,0,0};
        
    // }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> s;
        queue<pair<int,int>> q;
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    vector<pair<int,int>> t;
                    q.push({i,j});
                    int dx[] = {1,-1,0,0};
                    int dy[] = {0,0,-1,1};
                    while(!q.empty()){
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        t.push_back({x-i, y-j});
                        for(int i = 0; i < 4; i++){
                            int x_ = x + dx[i];
                            int y_ = y + dy[i];
                            if(x_ < 0 or y_ < 0 or x_ >= n or y_ >= m or grid[x_][y_] == 0) continue;
                            grid[x_][y_] = 0;
                            q.push({x_,y_});
                        }
                    }
                    s.insert(t);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends