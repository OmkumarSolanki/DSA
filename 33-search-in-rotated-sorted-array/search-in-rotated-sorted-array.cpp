class Solution {
public:
    int search(vector<int>& nums, int target) {
        // the idea is check which part is sorted
        // only find the target in the sorted part
        // if it does exist in the sorted part
        // move to the next part
        int n = nums.size();
        int low = 0, mid, high = n - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                // left array is sorted
                if ((nums[low] <= target) && (target <= nums[mid])) {
                    // target exist between low and mid
                    high = mid - 1;
                } else {
                    // target exists between mid and high
                    low = mid + 1;
                }
            } else {
                // nums[mid] <= nums[high]
                // right one is sorted
                if ((nums[mid] <= target) && (target <= nums[high])) {
                    // target exist between mid and high
                    low = mid + 1;
                } else {
                    // target exists between low and mid
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

/**
TC - O(logn)
SC - O(1)
**/