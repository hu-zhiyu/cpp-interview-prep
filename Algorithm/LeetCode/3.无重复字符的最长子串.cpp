/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
    // 时间复杂度：O(n), 左右指针会分别遍历一次字符串
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> us;
        int result = 0;
        int lptr = 0, rptr = 0;
        for(int i = 0; i < s.size(); i++) {
            lptr = i;
            if(i != 0) {
                us.erase(s[i - 1]);
            }
            while(rptr < s.size() && us.find(s[rptr]) == us.end()) {
                us.insert(s[rptr]);
                rptr++;
            }
            result = max(result, rptr - lptr);
        }
        return result;
    }
};
// @lc code=end

