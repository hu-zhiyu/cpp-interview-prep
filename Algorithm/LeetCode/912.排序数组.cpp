/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int sz = nums.size();
        quickSort(nums, 0, sz - 1);
        return nums;
    }
    void quickSort(vector<int> & nums, int begin, int end) {
        if(begin >= end) {
            return;
        }
        int pos = partition(nums, begin, end);
        quickSort(nums, begin, pos - 1);
        quickSort(nums, pos + 1, end);
    }
    int partition(vector<int> & nums, int begin, int end) {
        int key = nums[end];
        int i = begin - 1;
        for(int j = begin; j < end; j++) {
            if(nums[j] < key) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[end]);
        return i + 1;
    }
};
// @lc code=end

