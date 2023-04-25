//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    for(int i = 0; i < M; i++){
	        int ele1 = mat[0][i], ele2 = mat[N-1][i];
	        if(X >= ele1 and X <= ele2){
	            int l = 0, r = N-1;
	            while(l <= r){
	                int mid = (l + r)/2;
	                if(mat[mid][i] == X) return 1;
	                else if(mat[mid][i] > X) r = mid - 1;
	                else l = mid + 1;
	            }
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends