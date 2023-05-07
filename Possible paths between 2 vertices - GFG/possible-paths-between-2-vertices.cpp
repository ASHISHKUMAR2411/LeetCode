//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void solve(int vertex, int parent, vector<int> adj[], int &count, int &dest){
        if(vertex == dest ){
            count++;
            return;
        }
        for(auto i : adj[vertex]){
            if(i!=parent)
            solve(i, vertex,adj, count, dest);
        }
    }
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int src, int dest) {
        // Code here
        int count = 0;
        if(src == dest) count++;
        for(auto i : adj[src]){
            solve(i, src, adj, count, dest);
        }
        return count;
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
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends