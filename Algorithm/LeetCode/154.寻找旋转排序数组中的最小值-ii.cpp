/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        return binarySearch(nums, 0, sz - 1);
    }
    int binarySearch(vector<int>& nums, int start, int end) {
        if(start >= end) return nums[start];
        int mid = start + (end - start) / 2;
        if(nums[mid] < nums[end]) {  // 在mid左侧, 可能含mid
            return binarySearch(nums, start, mid);
        }
        else if(nums[mid] > nums[end]) {  // 在mid右侧且不含mid
            return binarySearch(nums, mid + 1, end);
        }
        else {
            return binarySearch(nums, start, end - 1);
        }
    }
};
// @lc code=end

