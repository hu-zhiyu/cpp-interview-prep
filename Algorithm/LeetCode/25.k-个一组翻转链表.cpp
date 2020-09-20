/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        ListNode* last = dummyhead;
        while(last) {
            while(last && count < k) {
                last = last->next;
                count++;
            }  
            if(last) {
                ListNode* cur = pre->next;
                while(count > 1) {
                    ListNode* temp = cur->next;
                    cur->next = temp->next;
                    temp->next = pre->next;
                    pre->next = temp;
                    count--;
                }   
                count--;
                pre = cur; 
                last = pre;
            }                  
        }
        return dummyhead->next;
    }
};
// @lc code=end

