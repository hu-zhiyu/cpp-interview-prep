/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int endpoint = ((n1 + n2) % 2 == 0) ? (n1 + n2) / 2 - 1 : (n1 + n2) / 2;
        int ptr1 = 0, ptr2 = 0;
        while((ptr1 < n1 || ptr2 < n2) && (ptr1 + ptr2) < endpoint) {
            if(ptr1 < n1 && ptr2 < n2) {
                (nums1[ptr1] < nums2[ptr2]) ? ptr1++ : ptr2++;
            }
            else if(ptr1 < n1) {
                ptr1++;
            }
            else {
                ptr2++;
            }
        }
        if((n1 + n2) % 2 == 0) {
            if(ptr1 < n1 && ptr2 < n2) {
                int temp1, temp2;
                (nums1[ptr1] < nums2[ptr2]) ? temp1 = nums1[ptr1++] : temp1 = nums2[ptr2++];
                if(ptr1 < n1 && ptr2 < n2) {
                    (nums1[ptr1] < nums2[ptr2]) ? temp2 = nums1[ptr1] : temp2 = nums2[ptr2];
                }
                else if(ptr1 < n1) {
                    temp2 = nums1[ptr1];
                }
                else {
                    temp2 = nums2[ptr2];
                }
                return (temp1 + temp2) / 2.0;
            }
            else if(ptr1 < n1) {
                return (nums1[ptr1] + nums1[ptr1 + 1]) / 2.0;
            }
            else {
                return (nums2[ptr2] + nums2[ptr2 + 1]) / 2.0;
            }
        }
        else {
            if(ptr1 < n1 && ptr2 < n2) {
                return (nums1[ptr1] < nums2[ptr2]) ? nums1[ptr1] : nums2[ptr2];
            }
            else if(ptr1 < n1) {
                return nums1[ptr1];
            }
            else {
                return nums2[ptr2];
            }            
        }
        return 0;
    }
};
// @lc code=end

