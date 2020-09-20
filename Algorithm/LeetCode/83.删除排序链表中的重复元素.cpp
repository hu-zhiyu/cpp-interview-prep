/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* header = head;
        ListNode* pre = head;
        while(head) {
            if(head->next && head->val != head->next->val)
                pre = head;
            else {
                while(head->next && head->val == head->next->val) {
                    head = head->next;
                }
            }
            head = head->next;
            if(head) pre->next = head;
        }
        return header;
    }
};
// @lc code=end

