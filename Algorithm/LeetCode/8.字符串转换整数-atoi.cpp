/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0) return 0;
        // 判断第一个非空白字符
        int i = 0;
        while(i < str.size() && !isValidCharacter(str[i])) {
            i++;
        }
        int j = i;

        while()

    }
    bool isValidCharacter(char c) {
        if(c == '-' || c = '+' || (c >= '0' && c <= '9')) {
            return true;
        }
        return false;
    }
};
// @lc code=end

