/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int curSum = 0;
        dfs(temp, candidates, res, curSum, target, 0);
        return res;
    }
    void dfs(vector<int>& temp, vector<int>& candidates, vector<vector<int>>& res, int curSum, int target, int begin) {
        if(curSum == target) {
            res.push_back(temp);
            return;
        }
        if(curSum > target) {
            return;
        } 
        for(int i = begin; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            dfs(temp, candidates, res, curSum + candidates[i], target, i);
            temp.pop_back();
        }
    }
};
// @lc code=end

