/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        while(pq.size() != 1 && !pq.empty()) {
            int temp1 = pq.top(); pq.pop();
            int temp2 = pq.top(); pq.pop();
            if(temp1 - temp2 > 0) pq.push(temp1 - temp2);
        }
        if(pq.size() == 1) return pq.top();
        else return 0;
    }
};
// @lc code=end

