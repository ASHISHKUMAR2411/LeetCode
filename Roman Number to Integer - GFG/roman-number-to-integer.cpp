//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int arr[26] = {0}; 
        // for(int i = 0;i<26;i++) arr[i] = 0;
        arr[('I'-'A')] = 1;
        arr[('V'-'A')] = 5;
        arr[('X'-'A')] = 10;
        arr[('L'-'A')] = 50;
        arr[('C'-'A')] = 100;
        arr[('D'-'A')] = 500;
        arr[('M'-'A')] = 1000;
        int sum = 0;
        reverse(s.begin(),s.end());
        char ch,ch1;
        for(int i =0;i<(int)(s.length());i++)
        {
            ch = s[i];
            if(i>0)
            ch1 = s[i-1];
            if(i && (arr[ch-'A']-arr[ch1-'A'])<0)
            {
                sum -= arr[ch-'A'];
            }
            else
            {
                sum += arr[ch-'A'];
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends