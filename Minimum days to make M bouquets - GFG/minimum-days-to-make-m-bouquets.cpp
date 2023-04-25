//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int M, int K, vector<int> &b){
      // Code here
      if(b.size() < (M*K)) return -1;
      int l = 1, r = *max_element(b.begin(), b.end());
      int mini = INT_MAX;
      while(l <= r){
          int m = (l + r)/2;
          int flo = 0, count = 0;
          for(int i = 0; i < b.size(); i++){
              if(b[i] <= m){
                  count++;
                  if(count == K){
                      flo++;
                      count = 0;
                  }
              }
              else{
                  if(count >= K){
                      flo++;
                  }
                  count = 0;
              }
          }
          if(flo >= M){
              mini = min(mini, m);
              r = m - 1;
          }
          else l = m + 1;
      }
      return mini;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends