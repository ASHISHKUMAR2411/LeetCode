class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> path_val(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        path_val[0][0] = grid[0][0];
        pq.push({path_val[0][0], {0,0}});
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!pq.empty()){
            int cx = pq.top().second.first;
            int cy = pq.top().second.second;
            pq.pop();
            if(cx == n-1 and cy == n-1) return path_val[n-1][n-1];
            for(int i = 0; i < 4; i++){
                int ax = cx + dx[i];
                int ay = cy + dy[i];
                if(ax >= n or ay >= n or ax < 0 or ay < 0) continue;
                int max_val = max(grid[ax][ay], path_val[cx][cy]);
                if(max_val < path_val[ax][ay]){
                    path_val[ax][ay] = max_val;
                    pq.push({path_val[ax][ay], {ax,ay}});
                }
            }
        }
        return -1;
    }
};