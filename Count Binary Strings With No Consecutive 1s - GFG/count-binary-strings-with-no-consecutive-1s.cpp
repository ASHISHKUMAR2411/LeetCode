//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
 
void multiply(long long F[2][2], long long M[2][2]);
void power(long long F[2][2], long long n);
int mod  = 1000000007;
 
// Function that returns nth Fibonacci number
int fib(long long n)
{
    long long F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
 
    return F[0][0]%mod;
}
 
// Optimized version of power() in method 4
void power(long long F[2][2], long long n)
{
    if(n == 0 || n == 1)
       return;
    long long M[2][2] = {{1, 1}, {1, 0}};
     
    power(F, n / 2);
    multiply(F, F);
     
    if (n % 2 != 0)
        multiply(F, M);
}
 
void multiply(long long F[2][2], long long M[2][2])
{
    long long x = ((F[0][0]%mod * M[0][0]%mod)%mod + (F[0][1]%mod * M[1][0]%mod)%mod)%mod;
    long long y =(( F[0][0]%mod * M[0][1]%mod)%mod + (F[0][1]%mod * M[1][1]%mod)%mod)%mod;
    long long z = ((F[1][0]%mod * M[0][0]%mod)%mod + (F[1][1]%mod * M[1][0]%mod)%mod)%mod;
    long long w = ((F[1][0]%mod * M[0][1]%mod)%mod + (F[1][1]%mod * M[1][1]%mod)%mod)%mod;
     
    F[0][0] = x%mod;
    F[0][1] = y%mod;
    F[1][0] = z%mod;
    F[1][1] = w%mod;
}
class Solution {
  public:
    int countStrings(long long int N) {
        // Code here
        int x = fib(N+2);
        return x;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends