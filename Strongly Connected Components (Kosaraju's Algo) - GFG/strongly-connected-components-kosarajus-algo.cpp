//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs_com(int node, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs_com(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    void dfs(int node, vector<bool> &vis, vector<int> adj[]){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        // using Kosa Raju's ALgorithm First 
        // We need to store the time of completion of the nodes, and store them in the stack, in order of compeltion 
        stack<int> st;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++)
            if(!vis[i])
                dfs_com(i, vis, adj, st);
        
        // we have the stack with node execution completed 
        // Now we have to reverse the node. 
        vector<int> adjr[n];
        for(int i = 0; i < n; i++){
            vis[i] = false;
            for(auto it : adj[i]){
                adjr[it].push_back(i);
            }
        }
        // adjr contain graph in the reverse order, 
        // now traverse the node with the completion time last 
        int count = 0;
        // vector<bool> visit(n, false);
        while(!st.empty()){
            int t = st.top();
            st.pop();
            if(!vis[t]){
                count++;
                // if we want to find the SCC components, then we store all the nodes of the dfs traversal it will be our one SCC, likewise for all will give all the SCCs
                dfs(t, vis, adjr);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends