class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // so we want to go to top
        // simple idea is if the slope is increasing then go forward
        // if the slope is decreasing then go backward

        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        // we need to handle the elements at start and end
        if (nums[0] > nums[1]) {
            return 0;
        } else if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }
        int low = 1, mid, high = n - 2;
        // we should start from low =1 to high = n-2
        // because we have already covered that case 
        while (low <= high) {
            mid = low + (high - low) / 2;

            if ((nums[mid] > nums[mid + 1]) && (nums[mid] > nums[mid - 1])) {
                return mid;
            }

            // if the slope is increasing
            if ((nums[mid - 1] < nums[mid]) && (nums[mid] < nums[mid + 1])) {
                low = mid + 1;
            }

            // if the slope is decreasing
            if ((nums[mid - 1] > nums[mid]) && (nums[mid] > nums[mid + 1])) {
                high = mid - 1;
            }

            // if there is a ditch we can go either way
            // 10 5 12
            if ((nums[mid - 1] > nums[mid]) && (nums[mid] < nums[mid + 1])) {
                high = mid - 1;
            }
        }
        return -1;
    }
};

/**
TC - O(logn)
SC - O(1)
**/