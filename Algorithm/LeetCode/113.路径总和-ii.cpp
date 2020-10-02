/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> tempRes;
        int curSum = root->val;
        tempRes.push_back(root->val);
        dfs(root, curSum, sum, tempRes, res);
        return res;
    }
    void dfs(TreeNode* root, int curSum, const int& sum, vector<int>& tempRes, vector<vector<int>>& res) {
        if(!root->left && !root->right) {
            if(curSum == sum) res.push_back(tempRes);
        }
        if(root->left) {
            tempRes.push_back(root->left->val);
            dfs(root->left, curSum + root->left->val, sum, tempRes, res);
            tempRes.pop_back();
        }
        if(root->right) {
            tempRes.push_back(root->right->val);
            dfs(root->right, curSum + root->right->val, sum, tempRes, res);
            tempRes.pop_back();
        }
    }
};
// @lc code=end

