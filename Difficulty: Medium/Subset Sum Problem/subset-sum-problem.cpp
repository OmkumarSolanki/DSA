class Solution {
  private:
    bool isSubsetSumExist(int index, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        
        if(sum == 0) {
            return true;
        }
        if(sum < 0) {
            return false;
        }
        if(index == -1) {
            return false;
        }
        
        if(dp[index][sum]!=-1) {
            return dp[index][sum];
        }
        
        bool take = isSubsetSumExist(index-1, sum-arr[index], arr, dp);
        bool notTake = isSubsetSumExist(index-1, sum, arr, dp);
        
        return dp[index][sum] = take || notTake;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // dp[n-1][target] represents if within the first n-1 elements 
        // does there exist a target if yes it would be true or else false
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return isSubsetSumExist(n-1, sum, arr, dp);
        
    }
        
        
};