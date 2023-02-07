//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
            vector<int> dp(n+1, 0);
            int maxi = 0, n_ind = -1, neg = 0, flag = 0;
            for(int i = 0; i < n; i++){
                if(!arr[i]){
                    flag = i+1;
                    neg = 0;
                    n_ind = -1;
                    continue;
                }
                if(arr[i] < 0){
                    neg++;
                    if(n_ind == -1){
                        n_ind = i;
                    }
                }
                if(neg%2 == 0){
                    maxi = max(maxi, i - flag + 1);
                }
                else{
                    maxi = max(maxi, i - n_ind);
                }
            }
            return maxi;
            
            
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends