class Solution {
public:
    int maxVowels(string s, int k) {
        int maxi = INT_MIN;
        vector<int> a(26,0);
        for(int i = 0; i < k; i++){
            a[s[i] - 'a']++;
        }
        int count = a[0] + a[8] + a[4] + a[14] + a[20];
        maxi = max(maxi, count);
        for(int i = k; i < s.length(); i++){
            a[s[i]-'a']++;
            a[s[i-k]-'a']--;
            count = a[0] + a[8] + a[4] + a[14] + a[20];
            maxi = max(maxi, count); 
        }
        return maxi;
    }
};