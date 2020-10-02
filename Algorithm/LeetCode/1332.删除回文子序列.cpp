/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 删除回文子序列
 */

// @lc code=start
class Solution {
public:
    int removePalindromeSub(string s) {
        int sz = s.size();
        if(sz == 0) return 0;
        for(int lptr = 0, rptr = sz - 1; lptr < rptr; lptr++, rptr--) {
            if(s[lptr] != s[rptr]) return 2;
        }
        return 1;

    }
};
// @lc code=end

