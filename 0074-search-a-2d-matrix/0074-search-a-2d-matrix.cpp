class Solution {
public:
    bool binarySearch(vector<int> &arr, int ele){
        int low = 0, high = arr.size() - 1, mid = 0;
        while(low<=high){
            mid = low + (high - low)/2;
            if(arr[mid] == ele) return true;
            else if(arr[mid]>ele) high = mid -1;
            else low = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i<(int)(matrix.size());i++){
            if(matrix[i][0] == target){
                return true;
            }
            else if(matrix[i][(int)(matrix[0].size()) - 1] == target ) return true;
            else if(matrix[i][0] < target && matrix[i][(int)(matrix[0].size()) - 1] > target){
                if(binarySearch(matrix[i], target)) return true;
                else return false;
            }
        }
        return false;
    }
};