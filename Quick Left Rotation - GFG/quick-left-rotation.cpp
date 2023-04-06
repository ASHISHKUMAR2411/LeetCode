//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   // O(n) time and O(k) space
	   k = k%n;
	   if(k > 0){
	   int a[k];
	   for(int i = 0; i < k; i++){
	       a[i] = arr[i];
	   }
	   for(int i = k; i < n; i++){
	       arr[i-k] = arr[i];
	   }
	   for(int i = 0; i < k; i++){
	       arr[n - k + i] = a[i];
	   }
	   }
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
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends