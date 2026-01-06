class Solution {
private:
    int calculateMaxMoney(vector<int>& nums) {
        int n = nums.size();
        int f0, f1, f2;
        f0 = nums[0];
        if (n == 1) {
            return f0;
        }
        f1 = max(nums[0], nums[1]);
        if (n == 2) {
            return f1;
        }
        for (int i = 2; i < n; i++) {
            int opt1 = 0, opt2 = 0;
            if (i - 2 >= 0) {
                opt1 = nums[i] + f0;
            }
            if (i - 1 >= 0) {
                opt2 = f1;
            }
            f2 = max(opt1, opt2);

            f0 = f1;
            f1 = f2;
        }
        return f2;
    }

public:
    int rob(vector<int>& nums) {
        // used same code from 198. House Robber
        // so in house robber 1
        // if we run two times once with first element excluded and second with
        // last element excluded then we will satify the condition for the
        // circle arrangement

        int n = nums.size();
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> nums1 = {nums.begin(), nums.end() - 1};
        vector<int> nums2 = {nums.begin() + 1, nums.end()};

        return max(calculateMaxMoney(nums1), calculateMaxMoney(nums2));
    }
};