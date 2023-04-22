//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int solve(vector<int> &arr, int i, int n, int k, int x){
        if(i == n){
            if(x == k) return 1;
            else return 0;
        }
        return solve(arr, i + 1, n, k, x ^ arr[i]) + solve(arr, i + 1, n, k , x);
    }
    int subsetXOR(vector<int> arr, int N, int k) {
        // code here
        int count = 0;
        // map<int,int> mp;
        return solve(arr, 0, N, k, 0);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends