//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int key) {
        // Code here
        int l = 0, h = N-1;
        while(l <= h){
            int mid = (l + h)/2;
            if(A[mid] == key) return true;
            else if(A[l]==A[mid]){l++; mid++;}
            else if(A[mid] > A[l]){
                if(key >= A[l] and key < A[mid]){
                    h = mid -1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(A[mid] < key and A[h] >= key){
                    l  = mid + 1;
                }
                else{
                    h = mid -1;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends