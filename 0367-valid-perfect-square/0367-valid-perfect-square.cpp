class Solution {
public:
    bool isPerfectSquare(int num) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = sqrt(num);
        if(n*n == num){
            return true;
        }
        else return false;
        
    }
};