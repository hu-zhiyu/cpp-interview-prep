/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int begin = 0;
        vector<int> temp;
        int curSum = 0;
        std::sort(candidates.begin(), candidates.end());
        dfs(begin, curSum, target, res, temp, candidates);
        return res;
    }
    void dfs(int begin, int curSum, int target, vector<vector<int>> & res, vector<int> & temp, vector<int>& candidates) {
        if(curSum == target) {
            if(find(res.begin(), res.end(), temp) == res.end())
                res.push_back(temp);
            return;
        }
        for(int i = begin; i < candidates.size(); i++) {
            if(curSum + candidates[i] > target) continue;
            temp.push_back(candidates[i]);
            dfs(i + 1, curSum + candidates[i], target, res, temp, candidates);
            temp.pop_back();
        }
    }
};
// @lc code=end

