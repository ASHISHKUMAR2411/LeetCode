//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class UnionFind{
  public:
      map<string, string> parent;
      map<string, int> rank;
      UnionFind(vector<vector<string>> details){
          for(int i = 0; i < details.size(); i++){
              for(int j = 1; j < details[i].size(); i++){
                  parent[details[i][j]] = details[i][j];
                  rank[details[i][j]] = 1;
              }
          }
      }
      string findParent(string s){
          if(s == parent[s]) return s;
          return parent[s] = findParent(parent[s]);
      }
      
      void findUnion(string s1, string s2){
          string s1p = findParent(s1);
          string s2p = findParent(s2);
          if(s1p == s2p) return;
          if(rank[s1p] > rank[s2p]){
              parent[s2p] = s1p;
          }
          else if(rank[s2p] > rank[s1p]){
              parent[s1p] = s2p;
          }
          else{
              parent[s2p] = s1p;
              rank[s1p] = rank[s2p]+1;
          }
      }
};
class Solution {
  public:
    void dfs(string node, map<string, set<string>> &adj, unordered_set<string> &vis, string &name, map<string, set<string>> &details){
        vis.insert(node);
        details[name].insert(node);
        for(auto it: adj[node]){
            if(vis.find(it) == vis.end()){
                dfs(it, adj, vis, name, details);
            }
        }
    }
    vector<vector<string>> mergeDetails(vector<vector<string>>& acc) {
        // code here
        map<string, set<string>> adj;
        // adjancecy list 
        for(int i = 0; i < acc.size(); i++){
            for(int j = 2; j < acc[i].size(); j++){
                adj[acc[i][j]].insert(acc[i][1]);
                adj[acc[i][1]].insert(acc[i][j]);
            }
        }
        int n = acc.size();
        unordered_set<string> vis;
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(vis.find(acc[i][1]) == vis.end()){
                map<string, set<string>> details;
                dfs(acc[i][1], adj, vis, acc[i][0], details);
                for(auto it: details){
                    vector<string> a;
                    a.push_back(it.first);
                    for(auto i : it.second){
                        a.push_back(i);
                    }
                    ans.push_back(a);
                }
            }
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return ans; 
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends