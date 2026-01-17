class Solution {
private:
    int findNumberOfWays(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        if(amount == 0) {
            return 1;
        }
        if(amount < 0) {
            return 0;
        }
        if(index == -1) {
            return 0;
        }

        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int take = 0, notTake = 0;
        if(amount - coins[index] >= 0) {
            take = findNumberOfWays(index, amount - coins[index], coins, dp);
        }
        notTake = findNumberOfWays(index-1, amount, coins, dp);

        return dp[index][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return findNumberOfWays(n-1, amount, coins, dp);
    }
};