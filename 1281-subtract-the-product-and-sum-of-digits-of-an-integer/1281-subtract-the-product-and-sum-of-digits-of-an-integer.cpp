class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, product = 1;
        while(n){
            product *= n%10;
            sum += n%10;
            n/=10;
        }
        return (product-sum);
    }
};