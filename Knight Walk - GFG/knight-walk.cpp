//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

	int minStepToReachTarget(vector<int>&k, vector<int>&t, int N){
	    // Code here
	    queue<pair<int,int>> q;
	    q.push(make_pair(k[0], k[1]));
	    vector<vector<int>> vis(N+1, vector<int>(N+1, 0));
	    int count = -1;
	    vis[k[0]][k[1]] = 1;
	    if(k[0] == t[0] and k[1] == t[1]){
	        return 0;
	    }
	    int dx[] = {-2,-2,-1,-1,1,1,2,2};
	    int dy[] = {-1,1,-2,2,-2,2,-1,1};
	    bool flag = false;
	    while(!q.empty()){
	        int s = q.size();
	        count++;
	        for(int i = 0; i < s; i++){
	            int x = q.front().first, y = q.front().second;
	            if(x == t[0] and y == t[1]) return count;
	           // if()
	            q.pop();
	            for(int j = 0; j < 8; j++){
	                int x_ = x + dx[j];
	                int y_ = y + dy[j];
	                if(x_ < 1 or y_ < 1 or x_ >= N+1 or y_ >= N+1 or vis[x_][y_] == 1) continue;
	                vis[x_][y_] = 1;
	                q.push(make_pair(x_,y_));
	            }
	        }
	    }
	    return -1;

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends