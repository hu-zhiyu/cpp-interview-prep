/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        if(sz == 1) return nums[0];
        vector<int> dp(nums);
        vector<bool> helper(sz, true);
        dp[1] = max(nums[0], nums[1]);
        helper[1] = dp[1] == nums[0] ? false : true;
        for(int i = 2; i < sz; i++) {
            if(helper[i-1]) {  // helper[i-1]为true表示dp[i-1]包含nums[i-1]
                dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
                helper[i] = dp[i] == dp[i-1] ? false : true;
            }
            else {
                dp[i] = max(dp[i-2] + nums[i], dp[i-1] + nums[i]);
                helper[i] = true;
            }
        }
        return dp[sz-1];
    }
};
// @lc code=end

