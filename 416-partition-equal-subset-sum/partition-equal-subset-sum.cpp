class Solution {
private:
    bool isSubsetOfDesiredSumPossible(int index, int sum, vector<int>& nums, vector<vector<int>>& dp) {

        if(sum == 0) {
            return true;
        }
        if(sum < 0) {
            return false;
        }
        if(index == -1) {
            return false;
        }

        if(dp[index][sum] != -1) {
            return dp[index][sum];
        }

        bool take = isSubsetOfDesiredSumPossible(index-1, sum-nums[index], nums, dp);
        bool notTake = isSubsetOfDesiredSumPossible(index-1, sum, nums, dp);

        return dp[index][sum] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        // I am checking if there exist a subset whose sum is totalSum/2
        // If the totalSum is Odd then it wont be possible

        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++) {
            totalSum = totalSum + nums[i];
        }
        if(totalSum & 1) {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>( totalSum/2 + 1, -1 ));
        return isSubsetOfDesiredSumPossible(n-1, totalSum/2 , nums, dp );

    }
};