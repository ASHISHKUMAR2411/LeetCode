//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int a[], int n, int x)
    {
        // code here
        int mini = INT_MAX, e1 = 0,e2 = 0, e3 = 0;
        sort(a, a+n);
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, h = n - 1;
            while(l < h){
                if(mini > abs(x - (a[i] + a[l] + a[h]))){
                    mini = abs(x - (a[i] + a[l] + a[h]));
                    e1 = i, e2 = l, e3 = h;
                }
                if((a[i] + a[l] + a[h]) > x){
                    h--;
                }
                else{
                    l++;
                }
            }
        }
        return a[e1] + a[e2] + a[e3];
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
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends