/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> resTemp;
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++) {
            if(i - 1 >= 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int lptr = i + 1, rptr = nums.size() - 1;
            while(lptr < rptr) {
                if(nums[lptr] + nums[rptr] > target) rptr--;
                else if(nums[lptr] + nums[rptr] < target) lptr++;
                else {
                    temp = {nums[i], nums[lptr], nums[rptr]};
                    if(resTemp.empty() || resTemp != temp) {
                        resTemp = temp;
                        res.push_back(resTemp);
                    }
                    lptr++;
                    rptr--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

