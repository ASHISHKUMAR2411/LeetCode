//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == num1)c1++;
            else if(nums[i] == num2)c2++;
            else if(c1 == 0){
                num1 = nums[i];
                c1++;
            }
            else if(c2 == 0){
                num2 = nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == num1)c1++;
            if(nums[i] == num2)c2++;
        }
        vector<int> ans;
        if(c1 > n/3){
            ans.push_back(num1);
        }
        if(c2 > n/3){
            ans.push_back(num2);
        }
        if(ans.size() == 0){
            ans.push_back(-1);
        }
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
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends