//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        if(n == 1) return arr[0];
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];
        int ele = -1;
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(arr[mid] != arr[mid - 1] and arr[mid] != arr[mid + 1]){
                return arr[mid];
            }
            else if(arr[mid] == arr[mid -1]){
                if((mid)%2 != 0){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if((mid)%2 != 0){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends