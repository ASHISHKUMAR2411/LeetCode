class Solution {
public:
    bool judgeSquareSum(int n) {
         // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        for (int i = 2;i * i <= n; i++)
        {
            int count = 0;
            if (n % i == 0)
            {
                // Count all the prime factors.
                while (n % i == 0)
                {
                    count++;
                    n /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return n % 4 != 3;
    }
};