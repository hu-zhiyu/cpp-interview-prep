/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    // 中序遍历
public:
    int minDiffInBST(TreeNode* root) {
        int pre, cur = INT_MIN / 2, minDiff = INT_MAX;
        inOrderTrav(root, pre, cur, minDiff);
        return minDiff;
    }
    void inOrderTrav(TreeNode* root, int& pre, int& cur, int& minDiff) {
        if(root->left) inOrderTrav(root->left, pre, cur, minDiff);
        pre = cur;
        cur = root->val;
        if(minDiff > cur - pre) minDiff = cur - pre;
        if(root->right) inOrderTrav(root->right, pre, cur, minDiff);
    }
};
// @lc code=end

