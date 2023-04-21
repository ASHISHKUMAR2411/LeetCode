class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
       vector<vector<int>> arr = board;
       int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int count = 0;
                if(i + 1 < n){
                    count += board[i+1][j] == 1;
                }
                if(j + 1 < m){
                    count += board[i][j + 1] == 1;
                }
                if(i-1 >= 0){
                    count += board[i - 1][j] == 1;
                }
                if(j - 1 >= 0){
                    count += board[i][j - 1] == 1;
                }
                if(i - 1 >= 0 and j - 1 >= 0){
                    count += board[i-1][j-1] == 1;
                }
                if(i - 1 >= 0 and j + 1 < m){
                    count += board[i-1][j+1] == 1;
                }
                if(i + 1 < n and j - 1 >= 0){
                    count += board[i+1][j-1] == 1;
                }
                if(i + 1 < n and j + 1 < m){
                    count += board[i+1][j+1] == 1;
                }
                if(board[i][j] == 1 and count < 2){
                    arr[i][j] = 0;
                }
                else if(board[i][j] == 1 and count > 3){
                    arr[i][j] = 0;
                }
                else if(board[i][j] == 0 and count == 3){
                    arr[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = arr[i][j];
            }
        }
    }
};