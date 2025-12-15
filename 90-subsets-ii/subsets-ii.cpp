class Solution {
private:
    void findSubsets(int i, vector<int>& nums, vector<vector<int>>& ans,
                     vector<int>& temp) {
        int n = nums.size();
        if (i == n) {
            ans.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[i]);
        findSubsets(i + 1, nums, ans, temp);

        // now to remove duplicates we need to ignore the duplicates when coming
        // back 1 1 2 if we take 1 at index 0 then we cannot take 1 at index 1
        // while starting a new subseq because it will be duplicate 1 at index 0
        // and 2 and index 2 - [1, 2] 1 at index 1 and 2 at index 2 - [1, 2]

        // If we take nums[i] at index i, we cannot take the same nums[i] at
        // index i+1 in the same subset. We can only include it in the current
        // subset if we are continuing from an earlier recursive call that
        // already included nums[i]

        while ((i + 1 < n) && (nums[i] == nums[i + 1])) {
            i++;
        }

        // not take
        temp.pop_back();
        findSubsets(i + 1, nums, ans, temp);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        // I have sorted the array inorder to remove duplicates
        findSubsets(0, nums, ans, temp);
        return ans;
    }
};