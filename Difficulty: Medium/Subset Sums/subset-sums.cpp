class Solution {
  private:
    void findSubSetSums(int i, vector<int>& arr, vector<int>& ans, int& currSum) {
        int n = arr.size();
        if(i == n) {
            ans.push_back(currSum);
            return;
        }
        
        // pick
        currSum = currSum + arr[i];
        findSubSetSums(i+1, arr, ans, currSum );
        
        // not pick
        currSum = currSum - arr[i];
        findSubSetSums(i+1, arr, ans, currSum );
        
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int currSum = 0;
        findSubSetSums(0, arr, ans, currSum);
        return ans;
    }
};