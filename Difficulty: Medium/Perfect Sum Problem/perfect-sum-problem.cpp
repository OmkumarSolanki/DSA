class Solution {
  private:
    int countSubsetOfSum(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if(index == -1) {
            if(target == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if(target < 0) {
            return 0;
        }
        if(index == -1) {
            return 0;
        }
        
        if(dp[index][target]!=-1) {
            return dp[index][target];
        }
        
        int take = countSubsetOfSum(index-1, target - arr[index], arr, dp);
        int notTake = countSubsetOfSum(index-1, target, arr, dp);
        
        return dp[index][target] = take + notTake;
        
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp( n, vector<int> (target+1, -1)  );
        return countSubsetOfSum(n-1, target, arr, dp);
        
    }
};