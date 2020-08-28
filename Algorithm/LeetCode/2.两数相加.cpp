/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* header = new ListNode(0);
        ListNode* pre = header;
        while(l1 && l2) {
            int value = l1->val + l2->val + carry;
            if(value / 10 == 1) {
                carry = 1;
            }
            else {
                carry = 0;
            }
            pre->next = new ListNode(value % 10);
            pre = pre->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 || l2) {
            ListNode* temp = ((l1 == nullptr) ? l2 : l1);
            while(temp) {
                int value = temp->val + carry;
                if(value / 10 == 1) {
                    carry = 1;
                }
                else {
                    carry = 0;
                }
                pre->next = new ListNode(value % 10);
                pre = pre->next;
                temp = temp->next;
            }
        }
        if(carry) {
            pre->next = new ListNode(1);
        }
        return header->next;
    }
};
// @lc code=end

