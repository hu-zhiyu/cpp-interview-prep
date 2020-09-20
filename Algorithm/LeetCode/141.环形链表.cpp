/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // 快慢指针
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* fasterPtr = head->next;
        ListNode* slowerPtr = head;
        while(fasterPtr && slowerPtr && fasterPtr != slowerPtr) {
            if(fasterPtr->next) fasterPtr = fasterPtr->next->next;
            else return false;
            slowerPtr = slowerPtr->next;
        }
        return fasterPtr == slowerPtr;
        
    }
};
// @lc code=end

