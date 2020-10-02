/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        return build(preorder, inorder, 0, 0, preorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int rootPos, int start, int end) {
        if(start > end) return nullptr;
        TreeNode* root = new TreeNode(preorder[rootPos]);
        int inPos = start;
        while(inPos < end && inorder[inPos] != preorder[rootPos]) inPos++;
        root->left = build(preorder, inorder, rootPos + 1, start, inPos - 1);
        root->right = build(preorder, inorder, rootPos + 1 + inPos - start, inPos + 1, end);
        return root;
    }

};
// @lc code=end

