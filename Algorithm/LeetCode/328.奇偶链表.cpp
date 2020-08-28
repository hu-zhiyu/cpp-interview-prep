/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddList = new ListNode();
        ListNode* evenList = new ListNode();
        ListNode* oddListHeader = oddList;
        ListNode* evenListHeader = evenList;
        
        while(head) {
            if(head->val % 2) {  // head指向奇数
                oddList->next = head;
                oddList = oddList->next;
            }
            else {
                evenList->next = head;
                evenList = evenList->next;
            }
            head = head->next;
        }
        oddList->next = nullptr;
        evenList->next = nullptr;
        oddList->next = evenListHeader->next;
        return oddListHeader->next;     
    }
};
// @lc code=end

