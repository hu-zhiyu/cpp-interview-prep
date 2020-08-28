/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz, 1);
        int result = 0;
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        for(int i = 0; i < sz; i++) {
            if(result < dp[i])
                result = dp[i];
        }
        return result;
    }
};
// @lc code=end

