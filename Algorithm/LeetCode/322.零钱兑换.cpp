/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        for(int i = 0; i < coins.size() + 1; i++) dp[i][0] = 0;
        for(int i = 1; i < coins.size() + 1; i++) {
            for(int j = 1; j < amount + 1; j++) {
                dp[i][j] = dp[i-1][j];
                if(j - coins[i-1] >= 0)
                    if(dp[i-1][j] >= 0 && dp[i][j-coins[i-1]] >= 0)
                        dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
                    else if(dp[i][j-coins[i-1]] >= 0)
                        dp[i][j] = dp[i][j-coins[i-1]] + 1;
                    else if(dp[i-1][j] >= 0)
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = -1;
            }
        }
        return dp[coins.size()][amount];
    }
};
// @lc code=end

