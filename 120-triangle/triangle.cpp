class Solution {
private:
    // TC - O(n*n)
    // SC - O(n*n) dp + O(n) recursive call stack
    int findMinimumPathSum(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();
        
        if( j > i ) {
            // we have 1 element in row 1 and same for other rows 
            return 200 * 10000;
        }

        if( i == n-1 ) {
            // When we are in last row we can return the value of the index
            return triangle[i][j];
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        // we can go down OR down + right
        int opt1 = triangle[i][j] + findMinimumPathSum(i+1, j, triangle, dp);
        int opt2 = triangle[i][j] + findMinimumPathSum(i+1, j+1, triangle, dp);

        dp[i][j] = min(opt1, opt2);

        return dp[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // I am considering it as nxm array
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return findMinimumPathSum(0, 0, triangle, dp);

        // TC - O(n*n)
        // SC - O(n*n) dp 
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = triangle[0][0];
        for(int i=1; i<n; i++) {
            for(int j=0; j<=i; j++) {
                int opt1 = INT_MAX, opt2 = INT_MAX;
                // opt1 -> above + left
                // opt2 -> above
                if(j-1>=0) {
                    opt1 = triangle[i][j] + dp[i-1][j-1]; 
                }
                if(j <= i-1) {
                    opt2 = triangle[i][j] + dp[i-1][j]; 
                }

                dp[i][j] = min(opt1, opt2);
            }
        }
        int minV = INT_MAX;
        for(int i=0; i<n; i++) {
            minV = min(minV, dp[n-1][i]);
        }
        return minV;
    }
};