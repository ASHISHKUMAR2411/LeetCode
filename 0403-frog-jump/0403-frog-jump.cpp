class Solution {
public:
    int dp[2001][2001];
    unordered_map<int, int> position; 
    // Top Down Approach
    bool solve(vector<int> &stones, int curr_index, int jump){
        if(curr_index == stones.size() - 1) return true;
        // we can go to three stones 
        if(dp[curr_index][jump] != -1) return dp[curr_index][jump];
        int stone1 = stones[curr_index] + jump - 1;
        int stone2 = stones[curr_index] + jump;
        int stone3 = stones[curr_index] + jump + 1;
        bool flag = false;
        if(stone1 > stones[curr_index] and position.find(stone1) != position.end()){
            int next_index = position[stone1];
            flag = flag || solve(stones, next_index, jump - 1);
        }
        if(stone2 > stones[curr_index] and position.find(stone2) != position.end()){
            int next_index = position[stone2];
            flag = flag || solve(stones, next_index, jump);
        }
        if(stone3 > stones[curr_index] and position.find(stone3) != position.end()){
            int next_index = position[stone3];
            flag = flag || solve(stones, next_index, jump + 1);
        }
        return dp[curr_index][jump] = flag == true ? 1 : 0;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i = 0; i < n; i++){
            position[stones[i]] = i;
        }
        // solve(stones, curr_ind, curr_jump)
        memset(dp, -1, sizeof(dp));
        return solve(stones, 0, 0);
    }
};