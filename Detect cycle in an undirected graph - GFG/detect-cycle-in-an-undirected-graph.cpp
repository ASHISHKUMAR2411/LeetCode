//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int i, int par, vector<int> adj[], vector<bool> &vis){
        vis[i] = true;
        for(auto j : adj[i]){
            if(j == par) continue;
            if(vis[j]) return true;
            if(dfs(j,i,adj,vis)){
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // two things to be care of 
        // first is that we have to check that the parent is not the current node, 
        // if we reach that node again, that means we have a cycle. 
        // using dfs 
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                bool cycle = dfs(i, -1,adj,vis);
                if(cycle) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends