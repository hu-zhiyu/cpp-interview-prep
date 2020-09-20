/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return head;
        ListNode* header = new ListNode(0);
        header->next = head;
        ListNode* pre = header;

        for(int i = 1; i < m; i++) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        for(int j = m; j < n; j++) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return header->next;
    }
};
// @lc code=end

