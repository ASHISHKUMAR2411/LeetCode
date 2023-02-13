//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* Function to replace every element with the
	next greatest element */
	void nextGreatest(int arr[], int n) {
	    // code here
	    stack<int> s;
	    s.push(arr[n-1]);
	    arr[n-1] = -1;
	    for(int i = n-2; i >= 0; i--){
    	       int x = arr[i];
    	       arr[i] = s.top();
	           while(!s.empty()){
	                if(s.top() < x){
	                    s.pop();
	                }
	                else{
	                    break;
	                }
	            }
	            if(s.empty())
    	            s.push(x);
	       // }
	    }
	}


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.nextGreatest(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends