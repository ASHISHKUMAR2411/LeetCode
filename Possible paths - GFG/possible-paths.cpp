//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int dfs(vector<int> adj[], int node, int &dest, int countpath, int &k, vector<vector<int>> &dp, int &mod){
        if(countpath == k){
            return node == dest;
        }
        if(dp[node][countpath] != -1) return dp[node][countpath];
        int ways = 0;
        for(auto it : adj[node]){
            ways = (ways%mod + dfs(adj, it, dest, countpath + 1, k, dp, mod)%mod)%mod;
        }
        return dp[node][countpath] = ways;
    }
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    // Code here
	    int n = graph.size();
	    vector<int> adj[n];
	    for(int i = 0; i < n; i++){
	       for(int j = 0; j < n; j++) {
	           if(graph[i][j]){
	               adj[i].push_back(j);
	           }
	       }
	    }
	    int mod = 1e9+7;
	    vector<vector<int>> dp(n, vector<int>(k+1,-1));
	    return dfs(adj, u, v, 0, k, dp, mod)%mod;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends