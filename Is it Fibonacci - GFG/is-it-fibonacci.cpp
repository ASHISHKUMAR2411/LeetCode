//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> G) {
        // code here
        if(N <= K){
            return G[N-1];
        }
        int i = 0;
        vector<long long> g(N, 0);
        long long sum = 0;
        for(i = 0; i < K; i++){
            g[i] = G[i];
            sum += G[i];
        }
        for(; i < N; i++){
            g[i] = sum;
            sum += g[i];
            sum -= g[i - K];
        }
        return g[N-1];
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends