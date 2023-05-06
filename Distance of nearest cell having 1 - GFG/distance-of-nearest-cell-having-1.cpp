//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int solve(int i, int j, int n, int m, vector<vector<int>> grid){
        if(i < 0 or j < 0 or i >= n or j >= m) return 0;
        if(grid[i][j] == 1) return 0;
        int d = solve(i+1,j,n,m,grid);
        int u = solve(i-1,j,n,m,grid);
        int r = solve(i, j+1,n,m,grid);
        int l = solve(i,j-1,n,m,grid);
        return 1 + min(u,min(d, min(l,r)));
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>>grid)
	{
	    // Code here
	   // int n = grid.size();
	   // int m = grid[0].size();
	   // vector<vector<int>> ans(n, vector<int>(m,0));
	   // for(int i = 0; i < n; i++){
	   //     for(int j = 0; j < m; j++){
	   //         if(grid[i][j] == 0)
    // 	            ans[i][j] = solve(i,j,n,m,grid);
	   //     }
	   // }
	   // return ans;
	   int n = grid.size();
	   int m = grid[0].size();
	   queue<pair<int,int>> q;
	   vector<vector<int>> ans(n,vector<int>(m,-1));
	   for(int i = 0; i < n; i++){
	       for(int j =0; j < m; j++){
	           if(grid[i][j] == 1){
	               ans[i][j] = 0;
	               q.push(make_pair(i,j));
	           }
	       }
	   }
	   int dx[] = {0,0,1,-1};
	   int dy[] = {1,-1,0,0};
	   while(!q.empty()){
	       int s = q.size();
	       for(int i = 0; i < s; i++){
	           int x = q.front().first, y = q.front().second;
	           q.pop();
	           for(int i = 0; i < 4; i++){
	               int x_ = x + dx[i];
	               int y_ = y + dy[i];
	               if(x_< 0 or y_ < 0 or x_ >= n or y_ >= m or ans[x_][y_] != -1) continue;
	               q.push(make_pair(x_,y_));
	               ans[x_][y_] = 1 + ans[x][y];
	           }
	       }
	   }
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends