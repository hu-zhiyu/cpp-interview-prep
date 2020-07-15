/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    // 迭代
public:
    ListNode* reverseList(ListNode* head){
        if(head == nullptr) return nullptr;      
        ListNode* temp = nullptr;
        ListNode* head_next = head->next; // 记录当前head的下一个结点
        head->next = nullptr; // 将第一个结点的next指向nullptr
        while(head_next != nullptr){
            temp = (*head_next).next;  // 记录下一个结点
            (*head_next).next = head;
            head = head_next;
            head_next = temp;
        }
        return head;
    }
};
// @lc code=end
/*
class Solution {
    // 递归
public:
    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head; // 递归基
        }
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};
*/