class Solution {
public:
    int maximumPopulation(vector<vector<int>>& l) {
        int p[2100];
        memset(p, 0, sizeof(p));
        for(int i = 0; i < l.size(); i++){
            p[l[i][0]]++;
            p[l[i][1]]--;
        }
        for(int i = 0; i < 2100; i++){
            if(i){
                p[i]+=p[i-1];
            }
        }
        int maxi = INT_MIN, j = 0;
        for(int i = 0; i < 2100; i++){
            if(p[i] > maxi){
                maxi = p[i];
                j = i;
            }
        }
        return j;
    }
};