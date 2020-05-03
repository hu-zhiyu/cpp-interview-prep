/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    // 迭代
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;
        stack<TreeNode*> m;
        m.push(root);
        while(!m.empty()){
            TreeNode* ele = m.top(); // 访问栈顶元素
            m.pop(); // 推出栈顶元素
            res.push_back((*ele).val);
            if(ele->right) m.push(ele->right);
            if(ele->left) m.push(ele->left);
        }
        return res;
    }
};
// @lc code=end
/*
class Solution {
    // 递归
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != nullptr){
            res.push_back((*root).val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
    }

};
*/
