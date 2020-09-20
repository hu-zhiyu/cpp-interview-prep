/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sumOfNums = 0;
        for(int i = 0; i < nums.size(); i++) {
            sumOfNums += nums[i];
        }
        if(sumOfNums % 2) return false;
        int sizeOfBag = sumOfNums / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sizeOfBag + 1, false));
        for(int i = 0; i <= nums.size(); i++) {
            dp[i][0] = true;
        }
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 1; j <= sizeOfBag; j++) {
                if(j - nums[i - 1] >= 0)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[nums.size()][sizeOfBag];
    }
};
// @lc code=end