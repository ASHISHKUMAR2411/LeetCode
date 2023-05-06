//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int sx = -1, sy = -1;
        int dx = -1, dy = -1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    sx = i; 
                    sy = j;
                }
                if(grid[i][j] == 2){
                    dx = i;
                    dy = j;
                }
                if(sx!=-1 and dx!=-1) break;
            }
            if(sx!=-1 and dx!=-1) break;
        }
        if(sx == dx and sy == dy) return true;
        queue<pair<int,int>> q;
        q.push(make_pair(sx,sy));
        int x[] = {0,0,-1,1};
        int y[] = {-1,1,0,0};
        while(!q.empty()){
            int px = q.front().first, py = q.front().second;
            q.pop();
            for(int i =0 ; i < 4; i++){
                int qx = px + x[i];
                int qy = py + y[i];
                if(qx < 0 or qy < 0 or qy >= m or qx >= n or grid[qx][qy] == 0 or grid[qx][qy] == -3) continue;
                if(qx == dx and qy == dy) return true;
                grid[qx][qy] = -3;
                q.push(make_pair(qx,qy));
            }
        }
        return false;
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends