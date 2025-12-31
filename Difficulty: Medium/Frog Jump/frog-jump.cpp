class Solution {
  private:
    // Recursion -> Top Down Approach
    int calculateMinCost(int n, vector<int>& height) {
        
        if(n==0) {
            return 0;
        }
        if(n==1) {
            return abs(height[1] - height[0]);
        }
        // height - 20 30 40 50
        // Ans -     0 10 
        // now we are at 40 i.e. index 2
        // opt 1 = jump from index 0 -> (40-20)-> Current Jump + the ans at index[n-2] i.e index[0] = 20
        // opt 2 = jump from index 1 -> (40-30) + 10 = 20
        
        // take jump 2 steps
        int opt1 = abs(height[n]-height[n-2]) + calculateMinCost(n-2, height);
        // take jump 1 steps
        int opt2 = abs(height[n]-height[n-1]) + calculateMinCost(n-1, height);
        return min(opt1, opt2);
    }
    // Recursion + Memoization -> Top Down Approach
    int calculateMinCost2(int n, vector<int>& height, vector<int>& dp) {
        
        if(n==0) {
            return 0;
        }
        if(n==1) {
            return abs(height[1] - height[0]);
        }
        
        if(dp[n]!=-1) {
            return dp[n];
        }
        
        // take jump 2 steps
        int opt1 = abs(height[n]-height[n-2]) + calculateMinCost2(n-2, height, dp);
        // take jump 1 steps
        int opt2 = abs(height[n]-height[n-1]) + calculateMinCost2(n-1, height, dp);
        return dp[n] = min(opt1, opt2);
    }
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        // return calculateMinCost(n-1, height);
        
        // Method 2
        vector<int> dp(n, -1);
        return calculateMinCost2(n-1, height, dp);
        
    }
};