class Solution {
private:
    void findCombinationSum(int i, vector<int>& candidates, int& target, int& csum, vector<int>& temp, vector<vector<int>>& ans){
        if( i == candidates.size()) {
            if(csum == target) {
                ans.push_back(temp);
            }
            return;
        }
        if( csum > target ) {
            return;
        }
        temp.push_back(candidates[i]);
        csum = csum + candidates[i];
        findCombinationSum(i+1, candidates, target, csum, temp, ans);
        temp.pop_back();
        csum = csum - candidates[i];
        while( (i+1 < candidates.size()) && (candidates[i]==candidates[i+1]) ) {
            i++;
        }
        findCombinationSum(i+1, candidates, target, csum, temp, ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        int currSum = 0;
        sort(candidates.begin(), candidates.end());
        findCombinationSum(0, candidates, target, currSum, temp, ans);
        return ans;
    }
};

/**
TC - O(2^n * k) k is the average length of a valid combination
K is basically the cost to copy the data only when a valid solution is found.
SC - O(n) Recursion stack space
**/