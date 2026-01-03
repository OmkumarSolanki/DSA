class Solution {
private:
    int calculateMinimumPathSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size(), n = grid[0].size();
        if (i >= m || j >= n) {
            return 200 * 200 * 200;
        }
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        dp[i][j] = grid[i][j] + min(calculateMinimumPathSum(i + 1, j, grid, dp),
                                calculateMinimumPathSum(i, j + 1, grid, dp));

        return dp[i][j];
    }

    int calculateMinimumPathSum1(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0) {
            return 200 * 200 * 200;
        }
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        dp[i][j] = grid[i][j] + min(calculateMinimumPathSum1(i - 1, j, grid, dp),
                                calculateMinimumPathSum1(i, j - 1, grid, dp));

        return dp[i][j];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        // We can go from end to start
        // We can also go from start to end
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return calculateMinimumPathSum(0, 0, grid, dp);
        return calculateMinimumPathSum1(m-1, n-1, grid, dp);

    }
};