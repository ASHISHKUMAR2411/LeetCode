//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& s, int N, int K) {
    // Write your code here.
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += s[i];
        }
        int maxi = INT_MIN, l = *min_element(s.begin(), s.end()), r = sum;
        while(l<=r){
            int mid = (l+r)/2;
            vector<int> v;
            sum = 0;
            for(int i = 0; i < N; i++){
                sum += s[i];
                if(sum >= mid){
                    v.push_back(sum);
                    sum = 0;
                }
            }
            if(v.size() >= K+1){
                l = mid + 1;
                int m = *min_element(v.begin(), v.end());
                maxi = max(maxi, m);
            }
            else{
                r = mid - 1;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends