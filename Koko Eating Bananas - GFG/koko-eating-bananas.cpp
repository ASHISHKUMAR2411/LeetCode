//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        
        if(H==1) return piles[0];
        sort(piles.begin(), piles.end());
        int l  = 1, r = piles[N-1], mini = INT_MAX;
        while(l <= r){
            int mid = (l + r)/2;
            int total = 0;
            for(int i = 0; i < N; i++){
                total += ceil((float)piles[i]/mid);
            }
            if(total <= H){
                mini = min(mini, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return mini;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends