class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n , 0);
        for(int i =0; i < n; i++){
            arr[i] = 2*i + 1;
        }
        int count = 0;
        if(n%2){
            int k = n/2;
            for(int i = 0; i < k; i++){
                count += arr[k] - arr[i];
            }
        }
        else{
            for(int i = 0; i < n/2; i++){
                count += arr[i];
            }
        }
        return count;
    }
};