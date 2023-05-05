class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }
            }
        }
        int count = 0, j = 0, i =0;
        while(!q.empty()){
            count++;
            int size = q.size();
            for(int k = 0; k < size; k++){
                pair<int,int> p = q.front();
                i = p.first, j = p.second;
                q.pop();
                if(i-1>=0 and grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    q.push(make_pair(i-1,j));
                }
                if(j-1 >= 0 and grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    q.push(make_pair(i,j-1));
                }
                if(i+1 < n and grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    q.push(make_pair(i+1,j));
                }
                if(j+1 < m and grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    q.push(make_pair(i, j+1));
                }
            }
        }
        bool flag = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    // q.push(make_pair(i,j));
                    flag = false;
                }
            }
        }
        if(flag and count == 0) return 0;
        if(flag and count)
            return count - 1;
        else return -1;
    }
};