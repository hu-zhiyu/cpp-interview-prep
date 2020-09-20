/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* dummyhead = new ListNode();
        auto comp = [](ListNode* const & a, ListNode* const & b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for(auto & m : lists) if(m) pq.push(m);
        if(pq.size() == 0) return nullptr;
        dummyhead->next = pq.top();
        ListNode* cur = dummyhead;
        while(!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            if(temp->next) pq.push(temp->next);
            cur->next = temp;
            cur = temp;
        }
        return dummyhead->next;

        
    }
};
// @lc code=end

