/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && nums[dq.front()] < nums[i]) dq.pop_front();
            dq.push_front(i);
            if(i - dq.back() >= k) dq.pop_back();
            if(i >= k - 1) res.push_back(nums[dq.back()]);
        }
        return res;
    }
};
// @lc code=end

