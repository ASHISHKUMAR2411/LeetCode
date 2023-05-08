//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &temp, vector<bool> &vis){
        vis[i] = true;
        temp.push_back(i);
        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it, adj, temp, vis);
            }
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        // using dfs to find the componenets 
        vector<bool> vis(V+1, false);
        int ans = 0;
        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                vector<int> temp;
                dfs(i, adj, temp, vis);
                bool flag = true;
                for(int j = 0; j < temp.size(); j++){
                    if(adj[temp[j]].size() < temp.size() - 1){
                        flag = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends