class Solution {
public:
    int power(long long a, long long b, long long m){
        int res = 1;
        while(b){
            if(b&1) res = (res *1ll* a)%m;
            a = (a*1ll*a)%m;
            b >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        if(n == 1) return 5;
        int m = 1e9 + 7;
        long long odd = (n + 1)/2;
        long long even = (n/2);
        odd = power(5,odd,m);
        even = power(4, even, m);
        return (odd*1ll*even)%m;
    }
};