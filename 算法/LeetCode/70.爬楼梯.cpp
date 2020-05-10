/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int res = 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int num1 = 1;
        int num2 = 2;
        for(int i = 3; i <= n; i++){
            res = num1 + num2;
            num1 = num2;
            num2 = res;
        }
        return res;
    }
};
// @lc code=end

