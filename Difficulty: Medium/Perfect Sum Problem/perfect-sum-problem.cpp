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
        // vector<vector<int>> dp( n, vector<int> (target+1, -1)  );
        // return countSubsetOfSum(n-1, target, arr, dp);
        
        // Tabulation
        // arr = 5 2 3 10 6 8
        // target = 10
        
        /**
        
           0  1. 2. 3. 4. 5. 6. 7. 8. 9. 10
        5. 1. 0. 0. 0. 0. 1. 0. 0. 0. 0.  0
        2  1
        3. 1
        10 1
        6. 1
        8. 1
        
        **/
        
        vector<vector<int>> dp( n, vector<int> (target+1, 0)  );
        for(int i=0; i<n; i++) {
            dp[i][0] = 1;
        }
        
        if( arr[0] <= target ) {
            dp[0][arr[0]]++;
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<=target; j++) {
                
                int take = 0;
                if(j - arr[i] >= 0) {
                    take = dp[i-1][j - arr[i]];
                }
                int notTake = dp[i-1][j]; 
                
                dp[i][j] = take + notTake;
                
            }
        }
        
        return dp[n-1][target];
        
        
        
    }
};