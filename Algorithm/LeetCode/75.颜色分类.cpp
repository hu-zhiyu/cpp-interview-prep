/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lptr = 0, rptr = nums.size() - 1, i = 0;
        while(i <= rptr) {
            if(nums[i] == 2) {
                swap(nums[i], nums[rptr--]);
            }
            else if(nums[i] == 0) {
                swap(nums[i++], nums[lptr++]);
            }
            else i++;
        }
    }
};
// @lc code=end

