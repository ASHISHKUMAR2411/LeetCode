//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DSU{
    
public:
    vector<int> parent, size, rank;
    DSU(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }
    void unionByRank(int x, int y){
        int px = findParent(x);
        int py = findParent(y);
        if(px == py) return;
        if(rank[px] > rank[py]){
            parent[py] = px;
        }
        else if(rank[px] < rank[py]){
            parent[px] = py;
        }
        else{
            parent[py] = px;
            rank[px] = rank[py] + 1;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
      bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
      }
      int MaxConnection(vector<vector<int>>& grid) {
        //   Using Disjoint Set
        int n = grid.size();
        DSU ds(n * n);
        // step - 1
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // step 2
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findParent(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findParent(cellNo)]);
        }
        return mx;
    }
    // // Using BFS Traveral 
    // int bfs(int i, int j, vector<vector<int>> grid){
    //     queue<pair<int,int>> q;
    //     q.push({i,j});
    //     int count = 0;
    //     int dx[] = {0,0,-1,1};
    //     int dy[] = {1,-1,0,0};
    //     int n = grid.size();
    //     while(!q.empty()){
    //         int x = q.front().first;
    //         int y = q.front().second;
    //         q.pop();
    //         count++;
    //         for(int k = 0; k < 4; k++){
    //             int x_ = x + dx[k];
    //             int y_ = y + dy[k];
    //             if(x_ >= n or y_ >= n or x_ < 0 or y_ < 0 or grid[x_][y_] == 0) continue;
    //             grid[x_][y_] = 0;
    //             q.push({x_, y_});
    //         }
    //     }
    //     return count - 1;
    // }
    // int MaxConnection(vector<vector<int>>& grid) {
    //     // code here
    //     // Applying Brute Force
    //     int count = 0, maxCon = 0, n = grid.size();
    //     for(int i = 0; i < n; i++){
    //         for(int j = 0; j < n; j++){
    //             if(grid[i][j] == 0){
    //                 grid[i][j] = 1;
    //                 count = bfs(i, j, grid);
    //                 grid[i][j] = 0;
    //                 maxCon = max(count, maxCon);
    //             }
    //             else{
    //                 count = bfs(i, j, grid);
    //                 maxCon = max(count, maxCon);
    //             }
                
    //         }
    //     }
    //     return maxCon ? maxCon : 1;
    // }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends