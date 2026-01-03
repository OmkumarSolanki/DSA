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
    // with memoization
    // TC - O(m*n)
    // SC - O(m*n)

    // without memoization - just pure recursion
    // TC - 2^(m+n)
    // SC - O(m+n) - recursive call stack

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
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return calculateMinimumPathSum(0, 0, grid, dp);
        // return calculateMinimumPathSum1(m-1, n-1, grid, dp);

        // Tabulation
        /**
        int sum = 0;
        for(int i=0; i<m; i++) {
            sum = sum + grid[i][0];
            dp[i][0] = sum;
        }
        sum = 0;
        for(int i=0; i<n; i++) {
            sum = sum + grid[0][i];
            dp[0][i] = sum;
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
        
        arr =
        1 3 1
        1 5 1
        4 2 1

        dp = 
        1 4 5
        2 6 6
        6 8 7
        **/

        // Space optimised Tabulation
        vector<int> prev(n, -1);
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum = sum + grid[0][i];
            prev[i] = sum;
        }

        for(int i=1; i<m; i++) {
            vector<int> curr(n, -1);
            curr[0] = prev[0] + grid[i][0];
            for(int j=1; j<n; j++) {
                curr[j] = grid[i][j] + min(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[n-1];

    }
};