/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int sz = 0;
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode* temp = dummyhead;
        while(temp->next) {
            sz++;
            temp = temp->next;
        }
        k %= sz;
        if(k == 0) return dummyhead->next;
        temp = dummyhead;
        for(int i = 0; i < sz - k; i++) {
            temp = temp->next;
        }
        ListNode* temp2 = temp->next;
        dummyhead->next = temp2;
        temp->next = nullptr;
        while(temp2->next) {
            temp2 = temp2->next;
        }
        temp2->next = head;
        return dummyhead->next;
    }
};
// @lc code=end

