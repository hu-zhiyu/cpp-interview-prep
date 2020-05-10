/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return ans;
        queue<TreeNode*> todo;
        todo.push(root);
        while(!todo.empty()){
            vector<TreeNode*> temp;
            vector<int> ans_part;
            int s = todo.size();
            for(int i = 0; i < s; i++){
                temp.push_back(todo.front());
                todo.pop();
                ans_part.push_back((*(temp[i])).val);
            }
            ans.push_back(ans_part);
            for(int i = 0; i < s; i++){
                if(temp[i]->left) todo.push(temp[i]->left);
                if(temp[i]->right) todo.push(temp[i]->right);
            }
        }
        return ans;

    }
};
// @lc code=end

