//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int N)
	{
	    // Code here
	    int count = 0;
	    queue<pair<int,int>> que;
	    que.push(make_pair(k[0], k[1]));
	    vector<vector<bool>> vis(N+1, vector<bool>(N+1, false));
	    int dx[] = {2,2,-2,-2,1,1,-1,-1};
	    int dy[] = {1,-1,1,-1,-2,2,2,-2};
	    vis[k[0]][k[1]] = true;
	    bool flag = false;
	    while(!que.empty()){
	        int size = que.size();
	        for(int j = 0; j < size; j++){
    	        auto top = que.front();
    	        que.pop();
    	        if(top.first == t[0] and top.second == t[1]){
    	           // flag = true;
    	            return count;
    	        }
    	        for(int i = 0; i < 8; i++){
    	            int x = top.first + dx[i];
    	            int y = top.second + dy[i];
    	            if(x < 1 or y < 1 or x > N or y > N or vis[x][y]) continue;
    	            vis[x][y] = true;
    	            que.push(make_pair(x,y));
    	        }
	        }
	        count++;
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