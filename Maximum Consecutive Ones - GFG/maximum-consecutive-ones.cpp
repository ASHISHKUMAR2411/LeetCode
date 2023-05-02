//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int l = 0, count = 0, maxi = INT_MIN; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                count++;
            }
            while(count > k){
                if(nums[l] == 0){
                    count--;
                }
                l++;
            }
            maxi = max(maxi, i - l + 1);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends