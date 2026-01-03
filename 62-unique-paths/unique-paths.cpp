class Solution {    
public:
    int uniquePaths(int m, int n) {
        /**
        we can go down or right only

        X - option 1
        |
      option 2

        m = 3 n = 4
        the dp array represents unique ways to reach that position

        1  1. 1. 1
        1  2. 3. 4
        1. 3. 6. 10

        dp[i][j] = dp[i-1][j] + dp[i][j-1]

        first row and first column there is only one way to reach there
        **/

        vector<vector<int>> dp(m, vector<int>(n, -1));
        // first columne
        for(int i=0; i<m; i++) {
            dp[i][0] = 1;
        }
        // first row
        for(int i=0; i<n; i++){
            dp[0][i] = 1;
        } 

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
        // TC - O(m*n)
        // SC - O(m*n) - dp size

    }
};