//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    // void solve(vector<int> &coins, int i, int taken, int sum, int &count, int &k, int &target){
    //     if(i == coins.size()) return;
    //     if(sum > target) return;
    //     if(taken > k) return;
    //     if(sum == target and taken == k){
    //         count++;
    //         return;
    //     }
    //     solve(coins, i, taken + 1, sum + coins[i], count, k, target);
    //     solve(coins, i+1, taken, sum, count, k, target);
    // }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        // int sum = 0;
        // int count = 0;
        // solve(coins, 0, 0, sum, count, K, target);
        // return count;
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < N; i++){
            if(coins[i] <= target){
                dp[coins[i]] = 1;
            }
        }
        for(int i = 1; i < K; i++){
            vector<int> dp1(target+1, 0);
            for(int j = 0; j <= target; j++){
                if(dp[j] == 1){
                    for(int k = 0; k < N; k++){
                        if(coins[k] + j <= target){
                            dp1[j+coins[k]] = 1;
                        }
                    }
                }
            }
            dp = dp1;
        }
        return dp[target] == 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends