//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        q.push({grid[0][0], {0, 0}});
        dp[0][0] = grid[0][0];
        int minCost = INT_MAX;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!q.empty()){
            auto top = q.top();
            int x = top.second.first;
            int y = top.second.second;
            int c = top.first;
            q.pop();                                                                 
            for(int i = 0; i < 4; i++){
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if(x_ >= n or y_ >= n or x_ < 0 or y_ < 0) continue;
                if(dp[x][y] + grid[x_][y_] < dp[x_][y_]){
                    dp[x_][y_] = dp[x][y] + grid[x_][y_];
                    q.push({dp[x_][y_], {x_, y_}});
                }
            }
        }
        return dp[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends