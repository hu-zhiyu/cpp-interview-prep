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
        queue<TreeNode*> q;
        q.push(root);
        int width = 0;
        vector<TreeNode*> vec;
        while(!q.empty()) {
            vector<TreeNode*> vec;
            bool leftmostNode = true;
            int counter = 0;
            while(!q.empty()) {
                TreeNode* temp = q.front();
                vec.push_back(temp);
                q.pop();
            }
            for(int i = 0; i < vec.size(); i++) {
                if(vec[i]->left) {
                    q.push(vec[i]->left);
                    if(leftmostNode) {
                        leftmostNode = false;
                        counter = 0;
                    }
                }
                counter++;
                if(vec[i]->left) {
                    if(width < counter) width = counter;
                }
                if(vec[i]->right) {
                    q.push(vec[i]->right);
                    if(leftmostNode) {
                        leftmostNode = false;
                        counter = 0;
                    }
                    if(width < counter) width = counter;
                }
                counter++;
                if(vec[i]->right) {
                    if(width < counter) width = counter;
                }
            }
        }
        return width;
    }
};
// @lc code=end

