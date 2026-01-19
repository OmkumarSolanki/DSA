class Solution {
private: 
    int findLCS(int i1, int i2, string& s1, string& s2, vector<vector<int>>& dp) {

        if(i1 < 0 || i2 < 0) {
            return 0;
        }

        if(dp[i1][i2]!= -1) {
            return dp[i1][i2];
        }

        if(s1[i1] == s2[i2]) {
            return dp[i1][i2] = 1 + findLCS(i1-1, i2-1, s1, s2, dp);
        } 
        return dp[i1][i2] = max( findLCS(i1-1, i2, s1, s2, dp), findLCS(i1, i2-1, s1, s2, dp) );
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findLCS(n-1, n-1, s, s2, dp);
    }
};