/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* tail = head;
        while(tail->next) {
            tail = tail->next;
        }
        quickSort(head, tail);
        return head;   
    }
    void quickSort(ListNode* head, ListNode* tail) {
        if(head == nullptr || tail == nullptr || head == tail || tail->next == head) return;
        pair<ListNode*, ListNode*> sep = partition(head, tail);
        quickSort(head, sep.first);
        quickSort(sep.second->next, tail);
    }
    pair<ListNode*, ListNode*> partition(ListNode* head, ListNode* tail) {
        int key = tail->val;
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        while(head != tail) {
            if(head->val < key) {
                dummyhead = dummyhead->next;
                // 交换
                int temp1 = dummyhead->val;
                dummyhead->val = head->val;
                head->val = temp1;  
            }   
            head = head->next;         
        }
        ListNode* pre = dummyhead;
        dummyhead = dummyhead->next;
        int temp2 = dummyhead->val;
        dummyhead->val = key;
        tail->val = temp2;
        return {pre, dummyhead};
    }
};
// @lc code=end

