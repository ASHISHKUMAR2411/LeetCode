//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> ans(n, 0);
	    int i = 0, j = 0, k = 0;
	    while(i < n and arr[i] < 0) i++;
	    while(j < n and arr[j] >= 0) j++;
	    bool flag = true;
	    while(i < n and j < n){
            if(flag){
                ans[k++] = arr[i++];
                while(i < n and arr[i] < 0) i++;
            }
            else{
                ans[k++] = arr[j++];
                while(j < n and arr[j] >= 0) j++;
            }
            flag = !flag;
	    }
	    while(i < n){
	        ans[k++] = arr[i++];
            while(i < n and arr[i] < 0) i++;
	    }
	    while(j < n){
	        ans[k++] = arr[j++];
            while(j < n and arr[j] >= 0) j++;
	    }
	    for(int i= 0; i < n; i++){
	        arr[i] = ans[i];
	    }
	   // cout << endl;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends