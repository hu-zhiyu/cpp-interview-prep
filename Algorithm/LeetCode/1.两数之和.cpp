/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = um.find(target - nums[i]);
            if(iter != um.end()) {
                return {i, iter->second};                
            }
            um[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

