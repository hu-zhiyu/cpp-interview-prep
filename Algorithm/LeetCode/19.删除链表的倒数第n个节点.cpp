/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* temp = dummyhead;
        ListNode* cur = dummyhead;
        for(int i = 0; i < n; i++) {
            temp = temp->next;
        }
        while(temp->next) {
            temp = temp->next;
            cur = cur->next;
        }
        ListNode* toDelete = cur->next;
        cur->next = toDelete->next;
        toDelete->next = nullptr;
        return dummyhead->next;
    }
};
// @lc code=end

