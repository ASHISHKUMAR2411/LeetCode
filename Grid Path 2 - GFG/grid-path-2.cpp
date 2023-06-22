//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    int dp[101][101];
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i == n-1 and j == m-1 and grid[i][j] == 0) return 1;
        if(i >= n or j >= m or i < 0 or j < 0 or grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (solve(i+1, j, n, m, grid)%mod + solve(i, j+1, n, m, grid)%mod)%mod;
        
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        memset(dp, -1, sizeof(dp));
        // if(grid[0][0] == 1) return 0;
        return solve(0, 0, n, m, grid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends