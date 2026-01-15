class Solution {
private:
    int findTotalCoins(int index, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        int n = coins.size();
        if(amount == 0) {
            return 0;
        }
        if(index == -1) {
            return 1e9;
        }
        if( amount < 0) {
            return 1e9;
        }
        if(dp[index][amount]!=-1) {
            return dp[index][amount];
        }

        int take = 1 + findTotalCoins(index, coins, amount - coins[index], dp);
        int notTake = findTotalCoins(index-1, coins, amount, dp);

        return dp[index][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = findTotalCoins(n-1, coins, amount, dp);
        if(ans == 1e9) {
            return -1;
        }
        return ans;
    }
};