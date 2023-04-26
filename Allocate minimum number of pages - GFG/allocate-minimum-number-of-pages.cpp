//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N < M) return -1;
        int sum = 0;
        for(int i= 0; i< N; i++){
            sum += A[i];
        }
        int l = *max_element(A, A+N) , r = sum;
        int mini = INT_MAX;
        while(l <= r){
            int mid = (l + r)/2;
            int count = 1; 
            sum = 0;
            bool f = true;
            for(int i = 0; i < N; i++){
                sum += A[i];
                if(sum > mid){
                    count++;
                    sum = A[i];
                }
                if(M < count){
                    f = false;
                }
            }
            if(f){
                r = mid - 1;
                mini = min(mini, mid);
            }
            else{
                l = mid + 1;
            }
        }
        if(mini == INT_MAX) return -1;
        else return mini;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends