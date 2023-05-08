//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool cycle(int i, vector<bool> &vis, vector<bool> &path, vector<int> adj[]){
        vis[i] = true;
        path[i] = true;
        
        for(auto it : adj[i]){
            if(!vis[it]){
                if(cycle(it, vis, path, adj)){
                    return true;
                }
            }
            else if(path[it]) return true;
        }
        
        path[i] = false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& p) {
	    // Code here
	   // if there is a cycle then it is not possible
	   vector<int> adj[N];
	   vector<bool> vis(N, false), path(N, false);
	   int m = p.size();
	   for(int i =0; i < m; i++){
	       adj[p[i].second].push_back(p[i].first);
	   }
	   for(int i = 0; i < N; i++){
	       if(!vis[i]){
	           if(cycle(i, vis, path, adj)){
	               return false;
	           }
	       }
	   }
	   return true;
	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends