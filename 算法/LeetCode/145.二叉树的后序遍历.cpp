/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return ans;
        stack<TreeNode*> m;
        TreeNode* last = nullptr; // 记录上一次push_back的结点，避免死循环 
        while(true){
            pushAlongLeftBranch(root, m, last);
            if(m.empty()) break;
            TreeNode* temp = m.top(); // temp没有左孩子
            if(temp->right && (temp->right) != last){
                // 如果temp有右孩子
                root = temp->right;
            }
            else{
                // 如果temp没有右孩子
                ans.push_back((*temp).val);
                last = m.top();
                m.pop();
                if(m.top()) root = m.top();
                else root = nullptr;
            }
        }
        return ans;
    }
    void pushAlongLeftBranch(TreeNode* root, stack<TreeNode*> & m, TreeNode* last){
        if(root == nullptr) return;
        while(root && root != last){
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return ans;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back((*root).val);
        return ans;
    }
};
*/