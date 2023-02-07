//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here
        int l = 0, r = 0, len = INT_MAX, sum = 0 ;
        while(l <= r and r <= n and l < n){
            if(sum <= x){
                if(r == n) break;
                sum += arr[r];
                r++;
            }
            else if(sum > x){
                len = min(len, r - l);
                sum -= arr[l];
                l++;
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends