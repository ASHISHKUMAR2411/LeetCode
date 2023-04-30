//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        int length =INT_MAX;
        for(int i=0; i < N; i++){
            int n = arr[i].size();
            length = min(length, n);
        }
        int l = 0, r = length;
        while(l <= r){
            int mid = (l + r)/2;
            bool flag = true;
            string k = arr[0].substr(0, mid);
            for(int i = 0; i < N; i++){
                if(arr[i].substr(0, mid) != k){
                    flag = false;
                    break;
                }
            }
            if(flag){
                l = mid + 1;
            }
            else{
                r = mid -1 ;
            }
        }
        string ans = arr[0].substr(0,r);
        if(ans == "") return "-1";
        return an;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends