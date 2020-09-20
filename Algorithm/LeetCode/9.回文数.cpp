/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long temp = 0;
        long long input = x;
        while(x > 0) {
            temp = 10 * temp + x % 10;
            x = x / 10;
        }
        if(temp == input) return true;
        return false;
    }
};
// @lc code=end

