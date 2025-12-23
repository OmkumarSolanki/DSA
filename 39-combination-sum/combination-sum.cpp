class Solution {
private:
    void findCombinationSum(int index, vector<int>& candidates, int target, vector<int>& temp, int csum, vector<vector<int>>& ans) {
        int n = candidates.size(); 

        if(csum > target) {
            return;
        }

        if(index == n) {
            if(csum == target) {
                ans.push_back(temp);
            }
            return;
        }
        
        temp.push_back(candidates[index]);
        csum = csum + candidates[index];
        findCombinationSum(index, candidates, target, temp, csum, ans);

        temp.pop_back();
        csum = csum - candidates[index];
        findCombinationSum(index+1, candidates, target, temp, csum, ans);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int csum = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        findCombinationSum(0, candidates, target, temp, csum, ans);
        return ans;
    }
};

/**
TC - 2^n * k - k for temp array
SC - O(n) - Recursive Stack
**/