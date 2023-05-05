//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int ncolor) {
        // Code here 
        // vector<int> adj[11];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int oldcol = image[sr][sc];
        // cout<<oldcol<<endl;
        bfs(sr,sc,ncolor,oldcol,vis,ans);
        // dfs(sr,sc,newColor,oldcol,vis,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends