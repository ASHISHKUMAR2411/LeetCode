//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 0;
    void dfs(int node, int parent, vector<bool> &vis, vector<int> adj[], vector<int> &low, vector<int> &high, set<int> &ans){
        vis[node] = true;
        low[node] = high[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                child++;
                dfs(it, node, vis, adj, low, high, ans);
                low[node] = min(low[node], low[it]);
                if(low[it] >= high[node] and parent != -1){
                    ans.insert(node);
                }
            }
            else{
                low[node] = min(low[node], high[it]);
            }
        }
        if(child > 1 and parent == -1) ans.insert(node);
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        // Only finding the children will not answer this question
        // We need to find reachability, if we can reach the node through another way.
        set<int> ans;
        vector<bool> vis(n, false);
        vector<int> low(n, 0), high(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, -1, vis, adj, low, high, ans);
            }
        }
        if(ans.size() == 0) return {-1};
        vector<int> answer;
        for(auto it : ans){
            answer.push_back(it);
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends