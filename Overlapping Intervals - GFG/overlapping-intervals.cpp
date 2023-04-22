//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& in) {
         // Code here
         vector<vector<int>> ans;
         sort(in.begin(), in.end());
         int start = in[0][0], end = in[0][1];
         int i =1, n = in.size(); 
         while(i < n){
             if(in[i][0] <= end){
                 end = max(end, in[i][1]);
             }
             else{
                 ans.push_back({start, end});
                 start = in[i][0];
                 end = in[i][1];
             }
             i++;
         }
         if(ans.size()){
             if(start != ans[ans.size() - 1][0]){
                 ans.push_back({start, end});
             }
         }
         else{
             ans.push_back({start, end});
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends