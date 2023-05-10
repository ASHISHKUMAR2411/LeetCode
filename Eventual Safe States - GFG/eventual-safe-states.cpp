//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        vector<int> a[V];
        vector<int> in(V,0);
        for(int i = 0; i < V; i++){
            for(int j = 0; j < adj[i].size(); j++){
                a[adj[i][j]].push_back(i);
            }
        }
        // we have reverse the adjacency list
        
        for(int i =0; i < V; i++){
            for(int j = 0; j  < a[i].size(); j++){
                in[a[i][j]]++;
            }
        }
        queue<int> q;
        for(int i =0; i < V; i++){
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto it : a[t]){
                in[it]--;
                if(in[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends