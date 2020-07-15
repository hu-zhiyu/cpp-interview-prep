/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
class Solution {
public:
    vector<int> volumn;
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum%4 != 0) return false;
        volumn = vector<int>(4, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return isValid(nums, sum/4, 0);
    }
    bool isValid(vector<int>& nums, int aveSum, int start){
        if(start == nums.size())
            return volumn[0]==volumn[1] && volumn[1]==volumn[2] && volumn[2]==volumn[3];
        for(int i=0; i<4; i++){
            if(nums[start]+volumn[i]>aveSum)
                continue;
            volumn[i] += nums[start];
            if(isValid(nums, aveSum, start+1))  return true;
            volumn[i] -= nums[start];
        }
        return false;
    }
};
// @lc code=end

