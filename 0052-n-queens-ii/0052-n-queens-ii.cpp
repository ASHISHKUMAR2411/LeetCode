class Solution {
public:
    void solve(int row, int n, int &ans, vector<int> &placed){
        if(row == n){
            ans++;
            return;
        }
        for(int col = 0; col < n; col++){
            bool safe = true;
            for(int pRow = 0; pRow < row; pRow++){
                int pCol = placed[pRow];
                if(col == pCol || abs(pRow - row) == abs(pCol - col)){
                    safe = false;
                    break;
                }
            }
            if(safe){
                placed.push_back(col);
                solve(row+1, n, ans, placed);
                placed.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0; 
        vector<int> placed;
        solve(0, n, ans, placed);
        return ans;
    }
};