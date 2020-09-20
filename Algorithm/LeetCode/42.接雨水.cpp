/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int res = 0, maxLeft = 0, maxRight = 0;
        vector<int> left(height.size());
        vector<int> right(height.size());
        for(int i = 0; i < height.size(); i++) {
            left[i] = maxLeft;
            if(height[i] > maxLeft) maxLeft = height[i];
        }     
        cout << endl;
        for(int i = height.size() - 1; i >= 0; i--) {
            right[i] = maxRight;
            if(height[i] > maxRight) maxRight = height[i];
        }        
        for(int i = 0; i < height.size(); i++) {
            int water = min(left[i], right[i]) - height[i];
            if(water > 0) res += water;
        }
        return res;
    }
};
// @lc code=end

