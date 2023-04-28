class Solution {
public:
    int search(vector<int> &arr, int target)
    {
        // Corner cases
        int n = arr.size();
        if (target <= arr[0])
            return arr[0];
        if (target >= arr[n - 1])
            return arr[n - 1];

        // Doing binary search
        int i = 0, j = n, mid = 0;
        while (i < j) {
            mid = (i + j) / 2;

            if (arr[mid] == target)
                return arr[mid];

            /* If target is less than array element,
                then search in left */
            if (target < arr[mid]) {

                // If target is greater than previous
                // to mid, return closest of two
                if (mid > 0 && target > arr[mid - 1])
                    return getClosest(arr[mid - 1],
                                      arr[mid], target);

                /* Repeat for left half */
                j = mid;
            }

            // If target is greater than mid
            else {
                if (mid < n - 1 && target < arr[mid + 1])
                    return getClosest(arr[mid],
                                      arr[mid + 1], target);
                // update i
                i = mid + 1;
            }
        }

        // Only single element left after search
        return arr[mid];
    }

    // Method to compare which one is the more close.
    // We find the closest by taking the difference
    // between the target and both values. It assumes
    // that val2 is greater than val1 and target lies
    // between these two.
    int getClosest(int val1, int val2,
                   int target)
    {
        if (target - val1 >= val2 - target)
            return val2;
        else
            return val1;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0, ele ;
        sort(arr2.begin(), arr2.end());
        for(int i = 0; i<(arr1.size()); i++ ){
            ele = search(arr2, arr1[i]);
            if(abs(ele-arr1[i]) > d){
                count++;
            }
        }
        return count;
    }
};