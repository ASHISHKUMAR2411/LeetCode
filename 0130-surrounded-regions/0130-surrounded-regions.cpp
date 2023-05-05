class Solution {
public:
    void solve(int i, int j, int n, int m, vector<vector<char>> &b){
        if(i<0 or j <0 or i >= n or j >= m or b[i][j] != 'O') return;
        b[i][j] = '#';
        solve(i-1, j, n,m,b);
        solve(i+1,j,n,m,b);
        solve(i,j-1,n,m,b);
        solve(i,j+1,n,m,b);
    }
    void solve(vector<vector<char>>& b) {
        int n = b.size(), m = b[0].size();
        for(int i = 0; i < m; i++){
            if(b[0][i] == 'O'){
                solve(0,i,n,m,b);
            }
            if(b[n-1][i] == 'O'){
                solve(n-1,i,n,m,b);
            }
        }
        for(int i = 0; i < n; i++){
            if(b[i][0] == 'O'){
                solve(i,0,n,m,b);
            }
            if(b[i][m-1] == 'O'){
                solve(i, m-1,n,m,b);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j= 0;j < m; j++){
                if(b[i][j] == '#'){
                    b[i][j] = 'O';
                }
                else if(b[i][j] == 'O'){
                    b[i][j] = 'X';
                }
            }
        }
    }
};