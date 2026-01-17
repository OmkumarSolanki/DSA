class Solution {
private:
    int findLCS(int index1, int index2, string& text1, string& text2, vector<vector<int>>& dp) {
        
        if(index1 == -1 || index2 == -1) {
            return 0;
        }

        if(dp[index1][index2] != -1) {
            return dp[index1][index2];
        }
 
        if(text1[index1] == text2[index2]) {
            return dp[index1][index2] = 1 + findLCS(index1-1, index2-1, text1, text2, dp);
        } else {
            return dp[index1][index2] = max( findLCS(index1-1, index2, text1, text2, dp),
                findLCS(index1, index2-1, text1, text2, dp) );
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // abcde ace
        // e == e -> 1 + (abcd, ac)
        // d != c
        // -> max( (abcd a), (abc, ac)   )

        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findLCS(n-1, m-1, text1, text2, dp);
    }
};