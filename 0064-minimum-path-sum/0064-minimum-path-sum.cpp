class Solution {
public:
    int solve(vector<vector<int>> &g,vector<vector<int>> &grid, int i, int j){
        if(i >= grid.size() || j >= grid[0].size()){
            return INT_MAX;
        }
        
        int down = INT_MAX, right = INT_MAX;
        if(i + 1 < grid.size() and g[i+1][j] != INT_MAX){
            down = g[i+1][j];
        }
        else{
            down = solve(g, grid, i+1, j);
        }
        if(j + 1 < grid[0].size() and g[i][j+1] != INT_MAX){
            right = g[i][j+1];
        }
        else{
            right = solve(g, grid, i, j + 1);
        }
        return g[i][j] = min(g[i][j], grid[i][j] + (min(down, right) == INT_MAX ? 0 : min(down, right)));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> g(grid.size() , vector<int>(grid[0].size(), INT_MAX));
        return solve(g,grid,0, 0);
    }
    // int solve(vector<vector<int>> &g, vector<vector<int>> &grid, int i, int j){
    //     if(i >= grid.size() || j >= grid[0].size()){
    //         return INT_MAX;
    //     }
    //     int below = INT_MAX, right = INT_MAX;
    //     if(i+1 < grid.size() and grid[i+1][j] != INT_MAX){
    //         below = grid[i+1][j];
    //     }
    //     else{
    //         below = solve(g, grid, i+1, j);
    //     }
    //     if(j+1 < grid[0].size() and grid[i][j+1] != INT_MAX){
    //         right = grid[i][j+1];
    //     }
    //     else{
    //         right = solve(g, grid, i, j+1);
    //     }
    //     return g[i][j] = min(g[i][j], grid[i][j] + (min(right, below) == INT_MAX ? 0 : min(below, right)));
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     vector<vector<int>> g(grid.size() , vector<int>(grid[0].size(), INT_MAX));
    //     return solve(g,grid,0, 0);
    // }
};