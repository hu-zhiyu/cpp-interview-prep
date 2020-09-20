/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int curPos = 0;
        int steps = 0;
        int temp = 0;
        for(int i = 0; i < nums.size();) {
            if(curPos >= nums.size() - 1)
                return steps;
            for(int j = 1; j <= nums[i]; j++) {
                if(i + j < nums.size()) {
                    if(i + j == nums.size() - 1)
                        return steps + 1;
                    if(i + j + nums[i + j] > temp) {
                        temp = i + j + nums[i + j];
                        curPos = i + j;
                    }                 
                }
                else {
                    return steps + 1;
                }
            }
            steps++;
            i = curPos;
        }
        return steps;
    }
};
// @lc code=end

