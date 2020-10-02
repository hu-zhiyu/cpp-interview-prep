/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int res = 0;
        int sz = A.size();
        vector<vector<int>> dp(2, vector<int>(sz, INT_MAX));
        dp[0][0] = 0;  // dp[0][i]表示不交换位置 i 元素使得位置 i 之前元素递增的最少交换次数
        dp[1][0] = 1;  // dp[1][i]表示交换位置 i 使得位置 i 之前元素递增元素的最少交换次数
        for(int i = 1; i < sz; i++) {
            if(A[i-1] < A[i] && B[i-1] < B[i]) {
                dp[0][i] = min(dp[0][i], dp[0][i-1]);
                dp[1][i] = min(dp[1][i], dp[1][i-1] + 1);
            }
            if(A[i-1] < B[i] && B[i-1] < A[i]) {
                dp[0][i] = min(dp[0][i], dp[1][i-1]);
                dp[1][i] = min(dp[1][i], dp[0][i-1] + 1);
            }
        }
        return min(dp[0][sz-1], dp[1][sz-1]);
    }
};
// @lc code=end

