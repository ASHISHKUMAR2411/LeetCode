//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        if(i < 0 or j < 0 or i >= n or j >= m or grid[i][j] != '1' or vis[i][j]) return;
        vis[i][j] = true;
        dfs(i-1,j,n,m,grid,vis);
        dfs(i+1,j,n,m,grid,vis);
        dfs(i,j-1,n,m,grid,vis);
        dfs(i,j+1,n,m,grid,vis);
        dfs(i-1,j-1,n,m,grid,vis);
        dfs(i+1,j+1,n,m,grid,vis);
        dfs(i-1,j+1,n,m,grid,vis);
        dfs(i+1,j-1,n,m,grid,vis);
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count =0 ;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    count++;
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends