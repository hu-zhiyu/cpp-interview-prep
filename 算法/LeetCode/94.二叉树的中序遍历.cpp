/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return ans;
        stack<TreeNode*> m;
        while(true){
            pushAlongLeftBranch(root, m);
            if(m.empty()) break;
            TreeNode* temp = m.top();
            ans.push_back((*temp).val);
            root = temp->right;
            m.pop();
        }
        return ans;
    }
    void pushAlongLeftBranch(TreeNode* root, stack<TreeNode*> & m){
        if(root == nullptr) return;
        while(root){
            m.push(root);
            root = root->left;
        }
        return;
    }
};
// @lc code=end
/*
class Solution {
    // 递归
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return ans; 
        inorderTraversal(root->left);
        ans.push_back((*root).val);
        inorderTraversal(root->right);
        return ans;
    }
};
*/

