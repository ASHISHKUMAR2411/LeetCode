//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X'){
                    // cout << i << " " << j << "->";
                    count++;
                    grid[i][j] = 'O';
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        // grid[x][y] = 'O';
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int x_ = x + dx[k];
                            int y_ = y + dy[k];
                            if(x_ < 0 or y_ < 0 or x_ >= n or y_ >= m or grid[x_][y_] != 'X') continue;
                            // cout << "(" << x_ << "," << y_ << ")";
                            grid[x_][y_] = 'O';
                            q.push({x_,y_});
                        }
                    }
                    // cout << endl;
                    
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends