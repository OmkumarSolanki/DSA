class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // the idea is check which part is sorted
        // only find the target in the sorted part
        // if it does exist in the sorted part
        // move to the next part
        int n = nums.size();
        int low = 0, mid, high = n - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }
            if ((nums[low] == nums[mid]) && (nums[mid] == nums[high])) {
                // If all the values are same
                // I am stuck so
                low++;
                high--;
            } else if (nums[low] <= nums[mid]) {
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
        return false;
    }
};

/**
[1,0,1,1,1] target is 0
previous code 33. Search in Rotated Sorted Array fails here

TC - O(logn)
SC - O(1)
**/