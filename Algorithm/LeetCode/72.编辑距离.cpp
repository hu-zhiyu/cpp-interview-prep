/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size();
        int sz2 = word2.size();
        if(sz1 == 0 && sz2 == 0) return 0;
        if(sz1 == 0) return sz2;
        if(sz2 == 0) return sz1;
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1));
        for(int i = 0; i < dp.size(); i++) dp[i][0] = i;
        for(int i = 0; i < dp[0].size(); i++) dp[0][i] = i;
        for(int i = 1; i < sz1 + 1; i++) {
            for(int j = 1; j < sz2 + 1; j++) {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
            }
        }
        return dp[sz1][sz2];
    }
};
// @lc code=end

