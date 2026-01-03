class Solution {
  private:
    int calculateMaxPoints(int n, int selected, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        
        if(n < 0) {
            return 0;
        }
        if(dp[n][selected]!=-1) {
            return dp[n][selected];
        }
        int ans = 0;
        for(int j=0; j<3; j++) {
            // we are looping for Running, Fighting and Learning
            if(selected != j) {
                // IMPORTANT arr[n][selected] not [n][j]
                ans = max(ans, arr[n][selected] + calculateMaxPoints(n-1, j, arr, dp) );
            }
        }
        return dp[n][selected] = ans;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Suppose at nth day I have done Running then 
        // on n-1th day I have to do Fighting or Learning
        // So we have two variables in this one
        // 1st is the nth day and what we have choosen on that day
        
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(3, -1));
        
        // on the last index I have three options
        // whether I can select Running, Fighting or learning
        // So I can get ansert by taking max of it
        // int opt1 = calculateMaxPoints(n-1, 0, arr, dp);
        // int opt2 = calculateMaxPoints(n-1, 1, arr, dp);
        // int opt3 = calculateMaxPoints(n-1, 2, arr, dp);
        
        // return max( opt1, max(opt2, opt3) );
        
        // Tabulation
        // now we want to start from index 0
        // dp[0][0] means we have selected running(0) at index 0
        // dp[0][0] represents maximum points earned at day 0 and by selected running
        /**
        
        dp[0][0] = arr[0][0];
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][2];
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<3; j++) {
                // at day i I have selected j activity
                // and by chosing j activity what max points I can achieve 
                // dp[i][j] = arr[i][j] + max( two remaining activities If I have selected J  );
                int points = 0;
                for(int k=0; k<3; k++) {
                    // this loop is that I have selected j activity today but to calcualte 
                    // value for today I need to check what other two activity has max values
                    // on the previous day
                    if(j!=k) {
                        points = max(points, arr[i][j] + dp[i-1][k] );
                    }
                    dp[i][j] = points;
                }
            }
        }
        
        return max( dp[n-1][0], max(dp[n-1][1], dp[n-1][2]) );
        
        **/
        
        /**
         1 2 5
         3 1 1 
         3 3 3
         
         dp array
         
         1 2  5
         8 6  3         3 + max(1, 5), 1 + max(1, 5), 2 + max(1,2)
         9 11 9
          
          
         **/
        
        // Space Optimised Tabulation
        // dp[0][0] = arr[0][0];
        // dp[0][1] = arr[0][1];
        // dp[0][2] = arr[0][2];
        
        vector<int> prev (3, -1);
        prev[0] = arr[0][0];
        prev[1] = arr[0][1];
        prev[2] = arr[0][2];
        
        for(int i=1; i<n; i++) {
            vector<int> curr (3, -1);
            for(int j=0; j<3; j++) {
                // at day i I have selected j activity
                // and by chosing j activity what max points I can achieve 
                // dp[i][j] = arr[i][j] + max( two remaining activities If I have selected J  );
                int points = 0;
                for(int k=0; k<3; k++) {
                    // this loop is that I have selected j activity today but to calcualte 
                    // value for today I need to check what other two activity has max values
                    // on the previous day
                    if(j!=k) {
                        // points = max(points, arr[i][j] + dp[i-1][k] );
                        points = max(points, arr[i][j] + prev[k] );
                    }
                    // dp[i][j] = points;
                    curr[j] = points;
                }
            }
            prev = curr;
        }
        
        // return max( dp[n-1][0], max(dp[n-1][1], dp[n-1][2]) );
        return max( prev[0], max(prev[1], prev[2]) );
        
    }
};