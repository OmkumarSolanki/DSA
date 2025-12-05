class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // Upper Bound means first value which is greater than not equal to
        // we need to return the index
        int n = arr.size();
        int low = 0, mid, high = n-1;
        while(low <= high) {
            mid = low + (high-low)/2;
            if(arr[mid] > target) {
                // valid
                high = mid - 1;
            } else {
                // arr[mid] <= target
                // not valid
                // need to increase the mid
                low = mid + 1;
            }
        }
        return low;
    }
};

/**
TC - O(logn)
SC - O(1)
**/