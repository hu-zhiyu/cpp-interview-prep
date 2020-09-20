/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        int res = 0;
        stack<int> s;
        vector<int> left(heights.size(), -1);  // left[i]记录位置i左边第一个小于height[i]的下标
        vector<int> right(heights.size(), heights.size());  // right[i]记录位置i右边第一个小于height[i]的下标
        for(int i = 0; i < heights.size();) {
            if(s.empty() || heights[s.top()] <= heights[i]){
                s.push(i++);
            }
            else {
                int temp = s.top();
                right[temp] = i;
                s.pop();
                if(!s.empty()) left[temp] = s.top();
            }
        }
        while(!s.empty()) {
            int temp = s.top();
            s.pop();
            if(!s.empty()) left[temp] = s.top();
        }
        for(int i = 0; i < heights.size(); i++) {
            int temp = heights[i] * (right[i] - left[i] - 1);
            if(temp > res) res = temp;
        }
        return res;
    }
};
// @lc code=end

