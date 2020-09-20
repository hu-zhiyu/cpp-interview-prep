/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push(pair(root, 0));
        unsigned long long width = 0;
        while(!q.empty()) {
            int curSize = q.size();
            width = max(width, q.back().second - q.front().second + 1);
            for(int i = 0; i < curSize; i++) {
                pair<TreeNode*, unsigned long long> temp = q.front();
                if(temp.first->left) q.push(pair(temp.first->left, 2 * temp.second + 1));
                if(temp.first->right) q.push(pair(temp.first->right, 2 * temp.second + 2));
                q.pop();
            }
        }
        return width;
    }
};
// @lc code=end

