//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int nums[], int n){
        //complete the function here
        int mini = INT_MAX;
        int l = 0, h = n - 1;
        while(l <= h){
            int mid = (l + h)/2;
            mini = min(mini, nums[mid]);
            mini = min(mini, min(nums[l], nums[h]));
            if(nums[mid] > nums[l]){
                mini = min(mini, nums[l]);
                l = mid + 1;
            }
            else{
                mini = min(mini, nums[mid]);
                h = mid - 1;
            }
        }
        return mini;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends