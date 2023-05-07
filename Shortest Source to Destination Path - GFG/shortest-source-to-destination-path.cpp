//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int dfs(int i, int j, int n, int m, vector<vector<int>> grid, int x, int y){
    //     if(i == x and j == y) return 0;
    //     if(i < 0 or j < 0 or i >= n or j >= m) return INT_MAX - 1;
    //     if(grid[i][j] == 0) return INT_MAX - 1;
    //     int u = 0, l = 0, r = 0, d = 0;
    //     u = dfs((i-1), j, n, m, grid, x, y);
    //     d = dfs(i+1, j, n, m, grid, x, y);
    //     l = dfs(i, j-1, n, m, grid, x, y);
    //     r = dfs(i, j+1, n, m, grid, x, y);
    //     int q = min(u, min(d, min(l, r)));
    //     if(q == INT_MAX - 1) return q;
    //     else return 1 + q;
    // }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        // in this we need to use the bfs other dfs might create problem of visited, as when the actual destination is visited by not the shortest path, then we have to backtrack and find the solution for every other 1   
        if(A[0][0] == 0) return -1;
        if(X == 0 and Y == 0) return 0;
        queue<vector<int>> q;
        q.push({0,0,0});
        A[0][0] = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!q.empty()){
            vector<int> a = q.front();
            q.pop();
            int x = a[0], y = a[1];
            for(int i = 0; i < 4; i++){
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if(x_ < 0 or y_ < 0 or x_ >= N or y_ >= M or A[x_][y_] == 0) continue;
                if(x_ == X and y_ == Y){
                    return a[2]+1;
                }
                A[x_][y_] = 0;
                q.push({x_,y_,a[2] + 1});
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends