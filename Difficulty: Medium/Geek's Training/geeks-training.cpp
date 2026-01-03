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
                ans = max(ans, arr[n][j] + calculateMaxPoints(n-1, j, arr, dp) );
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
        vector<vector<int>> dp(n, vector<int>(3, -1));
        
        // on the last index I have three options
        // whether I can select Running, Fighting or learning
        // So I can get ansert by taking max of it
        int opt1 = calculateMaxPoints(n-1, 0, arr, dp);
        int opt2 = calculateMaxPoints(n-1, 1, arr, dp);
        int opt3 = calculateMaxPoints(n-1, 2, arr, dp);
        
        return max( opt1, max(opt2, opt3) );
    }
};