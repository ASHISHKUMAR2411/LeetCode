//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &path){
        if(vis[node] and !path[node]) return false;
        if(path[node]) return true;
        vis[node] = true;
        path[node] = true;
        for(auto i : adj[node]){
            if(dfs(i, adj, vis,path)) return true;
        }
        path[node] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V, false), path(V, false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, path)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends