/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int lptr = 0, rptr = sz - 1;
        int res = (sz - 1) * min(height[0], height[sz - 1]);
        while(lptr < rptr) {
            height[lptr] < height[rptr] ? lptr++ : rptr--;
            int temp = (rptr - lptr) * min(height[lptr], height[rptr]);
            if(res < temp) res = temp;
        }
        return res;
    }
};
// @lc code=end

