//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int node, vector<bool> &vis, vector<int> adj[]){
        vis[node] = true;
        for(auto i : adj[node]){
            if(!vis[i]){
                solve(i, vis, adj);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        // creating adj list 
        vector<int> A[V+1];
        for(int i = 0; i < adj.size(); i++){
            for(int j = 0; j < adj[i].size(); j++){
                if(adj[i][j] == 1){
                    A[i+1].push_back(j+1);
                    A[j+1].push_back(i+1);
                }
            }
        }
        int count = 0;
        vector<bool> visited(V+1, false);
        for(int i = 1; i <= V; i++){
            if(!visited[i]){
                count++;
                solve(i, visited, A);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends