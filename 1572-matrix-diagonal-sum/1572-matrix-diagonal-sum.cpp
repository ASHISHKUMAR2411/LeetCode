class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0,n = (int)(mat.size());
        for(int i = 0;i<n;i++){
            sum+= mat[i][i]+mat[i][n-i-1];
        }
        if(n&1)
        sum -= mat[n/2][n/2];
        return sum;
    }
    
    
};