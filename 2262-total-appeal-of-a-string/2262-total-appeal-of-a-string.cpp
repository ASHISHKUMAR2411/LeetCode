class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0, n=s.size();
        for(char c = 'a'; c <= 'z'; c++){
            long long sum = 0, count = 0;
            for(int i= 0; i < n; i++){
                if(s[i] == c){
                    sum += ((count + 1) * count)/2;
                    count = 0;
                }
                else{
                    count++;
                }
            }
            sum += (count *1ll* (count + 1))/2;
            ans += ((n + 1) * n)/2 - sum;
        }
        return ans == 0 ? 1 : ans;
    }
};