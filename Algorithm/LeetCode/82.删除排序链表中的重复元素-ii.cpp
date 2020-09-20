/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        if(!head || !head->next) return head;
        ListNode* header = new ListNode();
        header->next = head;  // header: 哨兵节点
        ListNode* prev = header;
        while(prev && prev->next)
        {
            ListNode *curr = prev -> next;
            // 如果curr到最后一位了或者当前curr所指元素没有重复值
            if(!curr->next || curr->next->val != curr->val) prev = curr;
            else
            {
                // 将curr定位到一串重复元素的最后一位
                while(curr->next && curr->next->val == curr->val) curr = curr -> next;
                // prev->next跳过中间所有的重复元素
                prev -> next = curr -> next;
            }  
        }
        return header->next;       
    }
};
// @lc code=end

