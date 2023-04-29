class Solution {
public:
    int mySqrt(int x) {
        // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        long int j = 0;
        for(long int i = 1; i*i<=x;i++){
            if(i*i == x){
                return i;
            }
            else if(i*i >x){
                return j;
            }
            j = i;
        }
        return j;
    }
};