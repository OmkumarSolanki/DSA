class Solution {
private:
    // There is no need to pass i in function
    // void findPermutatioins(int i, vector<int>& nums, vector<int>& temp, vector<bool>& isVis, vector<vector<int>>& ans) {
    void findPermutatioins(vector<int>& nums, vector<int>& temp, vector<bool>& isVis, vector<vector<int>>& ans) {

        // I can choose element A at index1, also at Index2, .... Index n-1
        // if nums = [1,2,3] -> so I can choose 1 at index 0, Index 1 and Index
        // 2 I can choose 1 as my first Element, I can choose 2 as my first
        // Element, I can choose 3 as my first Index

        int n = nums.size();

        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isVis[i] == false) {
                temp.push_back(nums[i]);
                isVis[i] = true;
                // findPermutatioins(i + 1, nums, temp, isVis, ans);
                findPermutatioins(nums, temp, isVis, ans);
                temp.pop_back();
                isVis[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        vector<bool> isVis(n, false);
        findPermutatioins(nums, temp, isVis, ans);
        return ans;
    }
};

/**
TC- n! x n 
n! - we are generating n! permutaions and n because we are looping from 0 to n-1 for every permutauton
SC - O(n) + O(n)
O(n) for the isVis array and O(n) for the temp array
**/