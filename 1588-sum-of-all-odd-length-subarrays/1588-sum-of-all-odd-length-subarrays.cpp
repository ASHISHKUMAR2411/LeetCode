class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        // for(int i = 0;i<(int)(arr.size());i++){
        //     sum+= arr[i];
        // }
        for(int i = 0;i<(int)(arr.size());i++){
            for(int j = i;j<(int)(arr.size());j++){
                if((j-i)%2 == 0){
                    for(int k = i;k<=j;k++){
                        sum+=arr[k];
                    }
                }
            }
        }
        return sum;
    }
};