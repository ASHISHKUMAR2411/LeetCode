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
        queue<pair<int,int>> cornerIsland;
        for(int i = 0; i < N; i++){
            if(matrix[i][0] == 1){
                cornerIsland.push({i,0});
                matrix[i][0] = 0;
            }
            if(matrix[i][M-1] == 1){
                matrix[i][M-1] = 0;
                cornerIsland.push({i,M-1});
            }
        }
        for(int i = 0; i < M; i++){
            if(matrix[0][i] == 1){
                matrix[0][i] = 0;
                cornerIsland.push({0,i});
            }
            if(matrix[N-1][i] == 1){
                matrix[N-1][i] = 0;
                cornerIsland.push({N-1,i});
            }
        }
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!cornerIsland.empty()){
            int x = cornerIsland.front().first;
            int y = cornerIsland.front().second;
            cornerIsland.pop();
            for(int i = 0; i < 4; i++){
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if(x_ >= N or y_ >= M or x_ < 0 or y_ < 0) continue;
                if(matrix[x_][y_] == 1){
                    cornerIsland.push({x_, y_});
                    matrix[x_][y_] = 0;
                }
            }
        }
        int count = 0;
        for(int i =0 ; i < N; i++){
            for(int j = 0; j < M; j++){
                if(matrix[i][j] == 1){
                    count++;
                    matrix[i][j] = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int i = 0; i < 4; i++){
                            int x_ = x + dx[i];
                            int y_ = y + dy[i];
                            if(x_ >= N or y_ >= M or x_ < 0 or y_ < 0) continue;
                            if(matrix[x_][y_] == 1){
                                q.push({x_, y_});
                                matrix[x_][y_] = 0;
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