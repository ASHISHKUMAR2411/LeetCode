//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
         if(n == 1){
             vector<long long int> a(1, 1);
             return a;
         }
        //code here        
         vector<long long int> ans= nums, ans1 = nums, a(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            ans[i] *= ans[i - 1];
        }
        for(int i = nums.size() - 2; i >= 0; i--){
            ans1[i] *= ans1[i + 1];
        }
        for(int i = 0; i < nums.size(); i++){
            long long int pro = 1;
            if(i == 0)
                pro = ans1[1];
            else if( i == nums.size() - 1)
                pro = ans[i - 1];
            else{
                pro = pro * ans[i-1] * ans1[i+1];
            }
            a[i] = pro;
        }
        return a;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends