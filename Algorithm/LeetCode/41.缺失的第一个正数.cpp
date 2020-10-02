/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        for(int i = 0; i < sz;) { 
            if(nums[i] <= 0 || nums[i] == i + 1 || nums[i] > sz) {
                ++i;
                continue;
            }
            if(nums[i] > 0) {
                if(nums[i] == nums[nums[i] - 1]) {
                    ++i;
                    continue;
                }
                else swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < sz; i++) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return sz + 1;
    }
};
// @lc code=end

