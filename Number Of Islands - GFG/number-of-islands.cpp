//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DSU{
  public:
  vector<int> parent, rank, size;
  DSU(int n){
      parent.resize(n);
      rank.resize(n);
      size.resize(n);
      for(int i = 0; i < n; i++){
          parent[i] = i;
          rank[i] = 1;
          size[i] = 1;
      }
  }
  int findParent(int n){
      if(n == parent[n]) return n;
      return parent[n] = findParent(parent[n]);
  }
  
  void UR(int u, int v){
      int pu = findParent(u);
      int pv = findParent(v);
      if(pu == pv) return;
      if(rank[pu] > rank[pv]){
          parent[pv] = pu;
      }
      else if(rank[pv] > rank[pu]){
          parent[pu] = pv;
      }
      else{
          parent[pv] = pu;
          rank[pu] = rank[pv] + 1;
      }
  }
  void US(int u, int v){
      int pu = findParent(u);
      int pv = findParent(v);
      if(pu == pv) return;
      if(size[pu] > size[pv]){
          parent[pv] = pu;
          size[pu] += size[pv];
      }
      else{
          parent[pu] = pv;
          size[pv] += size[pu];
      }
  }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        // code here
        DSU ob(n*m);
        int k = op.size();
        vector<int> ans;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        int count = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        for(int i = 0; i < k; i++){
            int x = op[i][0];
            int y = op[i][1];
            if(vis[x][y]){
                ans.push_back(count);
                continue;
            }
            vis[x][y] = true;
            count++;
            for(int i = 0; i < 4; i++){
                int adjx = x + dx[i];
                int adjy = y + dy[i];
                if(adjx >= n or adjy >= m or adjx < 0 or adjy < 0) continue;
                if (vis[adjx][adjy] == 1) {
                    int nodeNo = x * m + y;
                    int adjNodeNo = adjx * m + adjy;
                        if (ob.findParent(nodeNo) != ob.findParent(adjNodeNo)) {
                            count--;
                            ob.US(nodeNo, adjNodeNo);
                        }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends