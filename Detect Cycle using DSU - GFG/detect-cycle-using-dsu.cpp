//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint{
    public: 
    vector<int> parent;
    Disjoint(int n){
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    
    int find_parent(int n){
        if(n == parent[n]) return n;
        return parent[n] = find_parent(parent[n]);
    }
    
    void combine(int u, int v){
        int pu = find_parent(u);
        int pv = find_parent(v);
        if(pu == pv) return;
        parent[pv] = pu;
    }
};

class Solution
{
    public:
    // void dfs(int node, int parent, vector<int> adj[], Disjoint &ob, bool &flag){
    //     ob.combine(parent, node);
    //     for(auto it : adj[node]){
    //         if(it != parent){
    //             if(ob.parent[it] == ob.parent[node]){
    //                 flag = true;
    //                 return;
    //             }
    //             else 
    //             dfs(it, node, adj, ob, flag);
    //         }
    //     }
    // }
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	   // while using dfs if two adjacent node has the same parent
	   // and none of them is the parent of any 
	   Disjoint ob(V);
	   bool flag = false;
	   for(int i = 0; i < V; i++){
	       for(auto it : adj[i]){
	           if(it > i){
	               if(ob.find_parent(it) == ob.find_parent(i)) return 1;
	               ob.combine(i, it);
	           }
	       }
	   }
	   return 0;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends