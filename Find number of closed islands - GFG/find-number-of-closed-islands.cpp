//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<vector<int>> vis(N, vector<int>(M,0));
        queue<pair<int,int>> q;
        // matrix first and last row
        for(int i = 0; i < M; i++){
            if(matrix[0][i] == 1){
                q.push({0,i});
            }
            if(matrix[N-1][i] == 1){
                q.push({N-1, i});
            }
        }
        
        // matrix first column and last column
        for(int i = 0; i < N; i++){
            if(matrix[i][0] == 1){
                q.push({i,0});
            }
            if(matrix[i][M-1] == 1){
                q.push({i, M-1});
            }
        }
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!q.empty()){
            pair<int,int> top = q.front();
            q.pop();
            int x = top.first, y = top.second;
            vis[x][y] = 1;
            for(int i = 0; i < 4; i++){
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if(x_ < 0 or x_ >= N or y_ >= M or y_ < 0 or vis[x_][y_] == 1 or matrix[x_][y_] == 0) continue;
                vis[x_][y_] = 1;
                if(matrix[x_][y_] == 1){
                    q.push({x_,y_});
                }
            }
            
        }
        int count = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(matrix[i][j] == 1 and vis[i][j] == 0){
                    count++;
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        auto top = q.front();
                        q.pop();
                        int x = top.first;
                        int y = top.second;
                        vis[x][y] = 1;
                        for(int k = 0; k < 4; k++){
                            int x_ = x + dx[k];
                            int y_ = y + dy[k];
                            if(x_ < 0 or x_ >= N or y_ >= M or y_ < 0 or vis[x_][y_] == 1 or matrix[x_][y_] == 0) continue;
                            vis[x_][y_] = 1;
                            if(matrix[x_][y_] == 1){
                                q.push({x_,y_});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends