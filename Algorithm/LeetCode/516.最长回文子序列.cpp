/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sz = s.size();
        if(sz == 0) return 0;
        if(sz == 1) return 1;
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        for(int i = 0; i < sz; i++) dp[i][i] = 1;
        for(int i = sz - 1; i >= 0; i--) {
            for(int j = i + 1; j < sz; j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][sz-1];
    }
};
// @lc code=end

