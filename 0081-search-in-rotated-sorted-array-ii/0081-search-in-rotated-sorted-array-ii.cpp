class Solution {
public:
    bool search(vector<int>& A, int key) {
        int N = A.size();
        int l = 0, h = N-1;
        while(l <= h){
            int mid = (l + h)/2;
            if(A[mid] == key) return true;
            else if(A[mid] == A[l]) mid++, l++;
            else if(A[mid] >= A[l]){
                if(key >= A[l] and key < A[mid]){
                    h = mid -1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(A[mid] < key and A[h] >= key){
                    l  = mid + 1;
                }
                else{
                    h = mid -1;
                }
            }
        }
        return false;
    }
};