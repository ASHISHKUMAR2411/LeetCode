//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        int l =0, r = 0;
        while(l < n and r < m){
            if(arr1[l] == arr2[r]){
                int x = arr1[l];
                int index = l ;
                ans.push_back(arr1[l]);
                while(l < n and arr1[l] == x){
                    l++;
                }
                if(l >= index){
                    l--;
                }
                index = r + 1;
                while(r < m and arr2[r] == x){
                    r++;
                }
                if(r >= index){
                    r--;
                }
                l++;
                r++;
            }
            else if(arr1[l] > arr2[r]){
                ans.push_back(arr2[r]);
                int x = arr2[r];
                int index = r + 1;
                while(r < m  and arr2[r] == x){
                    r++;
                }
                if(r >= index){
                    r--;
                }
                r++;
            }
            else{
                ans.push_back(arr1[l]);
                int x = arr1[l];
                int index = l + 1;
                while(l < n  and arr1[l] == x){
                    l++;
                }
                if(l >= index){
                    l--;
                }
                l++;
            }
        }
        while(l < n){
            ans.push_back(arr1[l]);
            int x = arr1[l];
            int index = l + 1;
            while(l < n and arr1[l] == x){
                l++;
            }
            if(l >= index){
                l--;
            }
            l++;
        }
        while(r < m){
            ans.push_back(arr2[r]);
            int x = arr2[r];
            int index = r + 1;
            while(r < m  and arr2[r] == x){
                r++;
            }
            if(r >= index){
                r--;
            }
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends