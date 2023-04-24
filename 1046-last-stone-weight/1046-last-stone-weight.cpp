class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        while(stones.size() > 1){
            int e1 = stones.back();
            stones.pop_back();
            int e2 = stones.back();
            stones.pop_back();
            if(e1 > e2){
                stones.push_back(e1 - e2);
                sort(stones.begin(), stones.end());
            }
        }
        if(stones.size() == 0){
            return 0;
        }
        else{
            return stones[0];
        }
    }
};