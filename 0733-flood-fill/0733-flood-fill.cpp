class Solution {
public:
    void bfs(int x,int y,int newcol,int oldcol,
    vector<vector<int>> &vis,vector<vector<int>> &ans){
        vis[x][y] = 1;
        ans[x][y] = newcol;
        int n = ans.size();
        int m = ans[0].size();
        queue<pair<int,int>>q;
        q.push({x,y});
        while(!q.empty()){
            int xc = q.front().first;
            int yc = q.front().second;
            q.pop();
            // Traversing neighbours
            vector<int> xcor = {0,-1,0,1};
            vector<int> ycor = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int newr = xc+xcor[i];
                int newc = yc+ycor[i];
                if(newr>=0 && newc>=0 && newr<n && newc<m
                &&  !vis[newr][newc] && ans[newr][newc]==oldcol){
                    ans[newr][newc] = newcol;
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> ans = image;
        vector<vector<int>> vis(n, vector<int>(m,0));
        bfs(sr,sc,color,image[sr][sc],vis,ans);
        return ans;
        
    }
};