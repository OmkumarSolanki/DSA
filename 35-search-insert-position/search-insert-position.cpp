class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Basically they are asking for lower Bound
        // first element which is greater than or equak to
        int n = nums.size();
        int low = 0, mid, high = n-1;
        while(low<=high) {
            mid = low + (high-low)/2;
            if (nums[mid]>=target) {
                // valid
                high = mid - 1;
            } else {
                // arr[mid] < target
                // not valid
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