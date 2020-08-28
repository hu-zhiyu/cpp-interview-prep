/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int max = 0x7fffffff, min = 0x80000000;
        long rx = 0;
        for(; x; rx = rx * 10 + x % 10, x /= 10);
        return (rx > max || rx < min) ? 0 : rx;
    }
};
// @lc code=end

