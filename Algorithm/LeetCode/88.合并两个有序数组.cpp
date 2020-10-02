/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n - 1;
        --m;
        --n;
        for(int i = tail; i >= 0; --i) {
            if(m >= 0 && n >= 0 && nums1[m] > nums2[n]) nums1[i] = nums1[m--];
            else if(m >= 0 && n >= 0) nums1[i] = nums2[n--];
            else if(m >= 0) nums1[i] = nums1[m--];
            else nums1[i] = nums2[n--];
        }
        return;
    }
};
// @lc code=end

