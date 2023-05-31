//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // taking priority queue for min heap like to store the weight in the ascending order we select the weight with the least weight
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0,-1}});
        vector<bool> vis(V, false);
        int sum = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second.first;
            int parent = top.second.second;
            int weight = top.first;
            if(!vis[node]){
                sum += weight;
                vis[node] = true;
                for(auto it : adj[node]){
                    if(!vis[it[0]]){
                        pq.push({it[1], {it[0], node}});
                    }
                }
            }
        }
        return sum;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends