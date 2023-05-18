//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& h) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int n = h.size(), m = h[0].size();
        vector<vector<int>> path(n,vector<int>(m,INT_MAX));
        path[0][0] = 0;
        int x[] = {-1,0,1,0};
        int y[] = {0,-1,0,1};
        while(!pq.empty()){
            auto t = pq.top();
            int wt = t.first;
            int r = t.second.first;
            int c = t.second.second;
            pq.pop();
            if(r == n-1 and c == m-1)
                return wt;
            for(int i=0;i<4;i++){
                int nr = r+x[i];
                int nc = c+y[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && path[nr][nc]> max(abs(h[r][c]-h[nr][nc]),wt)){
                    path[nr][nc] =  max(abs(h[r][c]-h[nr][nc]),wt);
                    pq.push({path[nr][nc],{nr,nc}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends