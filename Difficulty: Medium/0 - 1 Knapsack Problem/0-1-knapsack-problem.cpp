class Solution {
  private: 
    int findMaxValue(int index, int W, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp) {
        
        if(index == -1) {
            return 0;
        }
        if( W == 0 ) {
            return 0;
        }
        // this should be haldled earlier while calling recursion
        // if(W < 0) {
        //     return 0;
        // }
        
        if(dp[index][W]!=-1) {
            return dp[index][W];
        }
        
        int take = 0;
        if(W-wt[index] >= 0) {
            take = val[index] + findMaxValue(index-1, W-wt[index], val, wt, dp);
        }
        int notTake = findMaxValue(index-1, W, val, wt, dp);
        
        return dp[index][W] =  max(take, notTake);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (W+1, -1));
        return findMaxValue(n-1, W, val, wt, dp);
        
    }
};