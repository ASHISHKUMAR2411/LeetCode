//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        // int src = c;
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(c);
        vis[c] = true; 
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto it : adj[top]){
                if(!vis[it] and !(top == c and it == d)){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return vis[d] ? 0 : 1;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends