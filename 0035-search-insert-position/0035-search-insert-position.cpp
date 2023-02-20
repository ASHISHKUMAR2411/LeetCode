class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        int l = 0, r = arr.size()-1, m = 0;
        while (l <= r) {
            m = l + (r - l) / 2;

            // Check if x is present at mid
            if (arr[m] == x)
                return m;

            // If x greater, ignore left half
            if (arr[m] < x)
                l = m + 1;

            // If x is smaller, ignore right half
            else
                r = m - 1;
        }
        return l;
    }
};