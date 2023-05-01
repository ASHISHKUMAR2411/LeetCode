class Solution {
public:
    double average(vector<int>& s) {
        double sum = 0;
        for(int i = 0; i < s.size(); i++){
            sum += s[i];
        }
        sum -= *min_element(s.begin(), s.end());
        sum -= *max_element(s.begin(), s.end());
        return sum/(s.size() - 2);
    }
};