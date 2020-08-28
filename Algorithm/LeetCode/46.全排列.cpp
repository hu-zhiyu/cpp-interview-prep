/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int begin = 0;
        permutationHelper(nums, result, begin);
        return result;
    }
    void permutationHelper(vector<int>& nums, vector<vector<int>>& result, int begin) {
        if(begin == nums.size()) {
            result.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++) {
            std::swap(nums[i], nums[begin]);
            permutationHelper(nums, result, begin + 1);
            std::swap(nums[i], nums[begin]);
        }
    }
};
// @lc code=end

