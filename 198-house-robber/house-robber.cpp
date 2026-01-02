class Solution {
private:
    // Recursion
    int calculateMaxMoney(int n, vector<int>& nums) {
        // So suppose I am sitting on index n
        // then I want to decide should I take current index n or skip it and
        // take the index n-1
        // if I take the current index n then I have to skip the index n-1
        // If I skip the index at n then I can take the index at n-1
        if (n < 0) {
            return 0;
        }
        int opt1 = nums[n] + calculateMaxMoney(n - 2, nums);
        int opt2 = calculateMaxMoney(n - 1, nums);

        return max(opt1, opt2);
    }
    // Recursive trying a different base case
    int calculateMaxMoney1(int n, vector<int>& nums) {
        if (n == 0) {
            return nums[0];
        } else if (n == 1) {
            return max(nums[0], nums[1]);
        }

        int opt1 = 0, opt2 = 0;
        if (n - 2 >= 0) {
            opt1 = nums[n] + calculateMaxMoney1(n - 2, nums);
        }
        if (n - 1 >= 0) {
            opt2 = calculateMaxMoney1(n - 1, nums);
        }

        return max(opt1, opt2);
    }
    // Recursion + Memoization
    int calculateMaxMoney2(int n, vector<int>& nums, vector<int>& dp) {
        if (n == 0) {
            return nums[0];
        } else if (n == 1) {
            return max(nums[0], nums[1]);
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        int opt1 = 0, opt2 = 0;
        if (n - 2 >= 0) {
            opt1 = nums[n] + calculateMaxMoney2(n - 2, nums, dp);
        }
        if (n - 1 >= 0) {
            opt2 = calculateMaxMoney2(n - 1, nums, dp);
        }

        dp[n] = max(opt1, opt2);
        return dp[n];
    }
    // Recursion + Memoization
    int calculateMaxMoney3(int n, vector<int>& nums, vector<int>& dp) {
        if (n < 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        int opt1 = nums[n] + calculateMaxMoney3(n - 2, nums, dp);
        int opt2 = calculateMaxMoney3(n - 1, nums, dp);

        dp[n] = max(opt1, opt2);
        return dp[n];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return calculateMaxMoney(n - 1, nums);
        // return calculateMaxMoney1(n - 1, nums);

        vector<int> dp(n, -1);
        // return calculateMaxMoney2(n - 1, nums, dp);
        // return calculateMaxMoney3(n - 1, nums, dp);

        // Tabulation
        // dp[0] = nums[0];
        // if (n == 1) {
        //     return dp[0];
        // }
        // dp[1] = max(nums[0], nums[1]);
        // if (n == 2) {
        //     return max(nums[0], nums[1]);
        // }
        // for (int i = 2; i < n; i++) {
        //     int opt1 = 0, opt2 = 0;
        //     if (i - 2 >= 0) {
        //         opt1 = nums[i] + dp[i - 2];
        //     }
        //     if (i - 1 >= 0) {
        //         opt2 = dp[i - 1];
        //     }
        //     dp[i] = max(opt1, opt2);
        // }
        // return dp[n - 1];

        // Space Optimised Tabulation
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
};