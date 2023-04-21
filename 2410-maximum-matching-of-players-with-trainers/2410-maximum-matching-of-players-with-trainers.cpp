class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int i = 0,j =0;
        sort(p.begin(), p.end());
        int count =0 ;
        sort(t.begin(), t.end());
        while(i < p.size() and j < t.size()){
            if(p[i] <= t[j]){
                count++;
                i++;
                j++;
            }
            else j++;
        }
        return count;
    }
};