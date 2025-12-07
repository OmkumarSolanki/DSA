class Solution {
public:
    int findMin(vector<int>& nums) {
        // find the sorted array find the minimum in the sorted array and move
        // to the other part
        int n = nums.size();
        int low = 0, mid, high = n - 1;
        int ans = nums[0];
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) {
                // left one is sorted
                // consider the smallest one and move to other part
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                // nums[mid] <= nums[high]
                // right one is sorted
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

/**
TC - O(logn)
SC - O(1)
**/