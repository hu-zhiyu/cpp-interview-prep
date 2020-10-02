/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        int curSum = root->val;
        bool res = dfs(root, curSum, sum);
        return res;
    }
    bool dfs(TreeNode* root, int curSum, int sum) {
        if(!root->left && !root->right) {  // root is leaf node
            return curSum == sum;
        }
        bool left = false;
        bool right = false;
        if(root->left) left = dfs(root->left, curSum + root->left->val, sum);
        if(root->right) right = dfs(root->right, curSum + root->right->val, sum);
        return left || right;
    }
};
// @lc code=end

