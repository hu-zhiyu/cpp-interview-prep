/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> isReachable(nums.size(), false);
        isReachable[0] = true;
        int farthestPosition = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(farthestPosition >= i) {
                int tempPosition = nums[i] + i;
                if(tempPosition > farthestPosition)
                    farthestPosition = tempPosition;                
            }
            if(farthestPosition >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end

