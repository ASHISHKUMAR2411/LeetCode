//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int mini = INT_MAX;
        while(l <= r){
            int mid = (l + r)/2;
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                count += ceil((double)nums[i]/ mid);
            }
            if(count <= K){
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends