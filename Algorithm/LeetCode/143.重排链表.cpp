/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        int count = 0;
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        ListNode* formerPtr = head;
        while(head) {
            count++;
            head = head->next;
        }
        // reverse the latter half of the linked list
        count % 2 ? count = count / 2 + 1 : count = count / 2;
        while(count-- > 0) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        while(cur->next) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }

        ListNode* latterPtr = pre->next;
        pre->next = nullptr;
        while(formerPtr && latterPtr) {
            ListNode* ptr1 = formerPtr;
            ListNode* ptr2 = latterPtr;
            formerPtr = formerPtr->next;
            latterPtr = latterPtr->next;
            ptr1->next = ptr2;
            ptr2->next = formerPtr;
        }
    }
};
// @lc code=end

