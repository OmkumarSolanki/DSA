class Solution {
private: 
    void findSubsetsOfDesiredSum(int index, vector<int>& candidates, int& target, vector<int>& temp, vector<vector<int>>& ans, int& csum) {
        // we have two options one to take it and one to avoid it
        int n = candidates.size();

        // Most Important
        if(csum > target) {
            return;
        }

        if(index == n) {
            if(target == csum) {
                ans.push_back(temp);
            }
            return;
        }

        // take it
        csum = csum + candidates[index];
        temp.push_back(candidates[index]);
        // we can take a single element multiple times
        findSubsetsOfDesiredSum(index, candidates, target, temp, ans, csum);

        // leave it
        csum = csum - candidates[index];
        temp.pop_back();
        findSubsetsOfDesiredSum(index+1, candidates, target, temp, ans, csum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        int csum = 0;
        findSubsetsOfDesiredSum(0, candidates, target, temp, ans, csum);
        return ans;
    }
};

/**
TC - O(2*n) - approx - the more correct answer is exponential
SC - Recursive Stack - O(n)
**/