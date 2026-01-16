class Solution {
private:
    int findSubsetSum(int index, vector<int>& nums, int target, vector<vector<int>> &dp) {
        if(index == -1) {
            if(target == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        if(target < 0) {
            return 0;
        }
        if(dp[index][target]!=-1) {
            return dp[index][target];
        }

        int take = 0;
        if(target - nums[index] >= 0) {
            take = findSubsetSum(index-1, nums, target - nums[index], dp);  
        }
        int notTake = findSubsetSum(index-1, nums, target, dp);

        return dp[index][target] = take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // S1 - S2 = Target
        // S1 + S2 = Total
        // 2S1 = Target + Total
        // S1 = (Target + Total)/2;
        // Now we need to find how many subsets exist of the Sum S1
        // Lets also check for S2
        // -2S2 = Target - Total
        // S2 = (total-target)/2;
        
        
        int n = nums.size(), total = 0;

        for(int i=0; i<n; i++) {
            total = total + nums[i];
        }
        
        if( ((total-target)&1) == 1 ) {
            return 0;
        }

        if( (total-target) < 0 ) {
            return 0;
        }

        int newTarget = (total-target)/2;
        vector<vector<int>> dp(n, vector<int>(newTarget +1, -1));
        return findSubsetSum(n-1, nums, newTarget, dp);
    }
};

/**
nums [1] target 2 = op 0
nums [1000] target -1000 op = 1
nums [0] target 0 op = 2
nums [2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53] target 1000
**/