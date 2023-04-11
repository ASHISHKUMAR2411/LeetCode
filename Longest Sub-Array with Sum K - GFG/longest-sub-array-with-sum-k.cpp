//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int sum = 0, max_l = 0;
        // Complete the function
        unordered_map<int,int> mp;
        for(int i = 0; i < N; i++){
            sum += A[i];
            if(sum == K){
                max_l = max(max_l, i + 1);
            }
            if(mp.find(sum) == mp.end()){
               mp[sum] = i;
            }
            if(mp.find(sum - K) != mp.end()){
                int j = mp[sum - K];
                max_l = max(max_l, i - j);
            }
        }
        return max_l;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends