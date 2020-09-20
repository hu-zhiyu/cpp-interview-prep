/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0) return result;
        if(nums.size() == 1) {
            result.push_back(nums); 
            return result;
        }
        int begin = 0;
        helper(nums, result, begin);
        return result;
    }
    void helper(vector<int>& nums, vector<vector<int>> & result, int begin) {
        if(begin == nums.size() - 1) {
            if(find(result.begin(), result.end(), nums) == result.end())
                result.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++) {
            if(begin == i || nums[begin] != nums[i]) {
                swap(nums[begin], nums[i]);
                helper(nums, result, begin + 1);
                swap(nums[begin], nums[i]);                
            }
        }
        return;
    }
};
// @lc code=end

