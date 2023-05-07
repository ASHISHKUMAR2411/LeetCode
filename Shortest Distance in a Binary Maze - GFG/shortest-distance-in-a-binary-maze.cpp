//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
                     pair<int, int> d) {
        // code here
        int n = grid.size(), m = grid[0].size();
        if(s.first == d.first and s.second == d.second) return 0;
        if(grid[s.first][s.second] == 0 || grid[d.first][d.second]  == 0) return -1;
        queue<vector<int>> q;
        q.push({s.first, s.second, 0});
        grid[s.first][s.second] = 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            vector<int> a = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = a[0] + dx[i] , y = a[1] + dy[i];
                if(x < 0 or y < 0 or x >= n or y >= m or grid[x][y] == 0) continue;
                if(x == d.first and y == d.second) return a[2] + 1;
                grid[x][y] = 0;
                q.push({x,y,a[2] + 1});
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends