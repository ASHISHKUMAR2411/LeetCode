//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int maxi = 0, count = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int dx[] = {1,-1,1,-1,0,0,1,-1};
        int dy[] = {1,-1,-1,1,1,-1,0,0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                count = 0;
                if(grid[i][j] == 1){
                    count++;
                    grid[i][j] = 0;
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k = 0; k <8; k++){
                            int x_ = dx[k] + x;
                            int y_ = y + dy[k];
                            if(x_ < 0 or y_ < 0 or x_ >= n or y_ >= m or grid[x_][y_] == 0) continue;
                            count++;
                            q.push({x_, y_});
                            grid[x_][y_] = 0;
                        }
                    }
                    maxi = max(maxi, count);
                }
            }
        }
        return maxi;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends